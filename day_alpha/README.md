# Linux/Android kernel research day-alpha

### Object

`prob/` 폴더에 제공되는 파일들을 이용해 쉘을 획득, 또는 임의 명령 실행하는 exploit 프로그램 작성.
단, Exploit code는 C로 작성 되어야 하며 interactive shell이 아닌 1회성 command execution도 허용.
Local, Remote 제한 없이 Exploit을 통해  쉘을 획득하거나 임의 명령 실행이 가능해야함.

### Submit

dolpin1402@gmail.com 으로 제목은 `"[LinKern] Day-alpha 작성자 submit"`

기한은 2020-01-12 23:59:59 까지

### Q&A

##### `exp.py` 파일은 무엇인가요?

제공되는 `exp.py` 파일은 python으로 작성된 sample exploit code입니다. 본 과제가 요구하는점은 해당 exploit code를 참고하여 c로 작성된 exploit code를 만드는 것입니다. 