# Cpp-Calculatior

## 1. 프로젝트 소개
![계산기](https://blog.kakaocdn.net/dn/qG7Js/btrsrmhEfEj/BMpSJzPMcvootvkro59KYk/img.gif)

GUI 계산기를 만들었습니다. 포인터를 조작하여 네모칸을 눌러 표현식을 입력할 수도 있고 키보드로 바로 입력할 수도 있습니다. 
또한 유효하지 않은 계산식을 입력할 경우 화면에 오류를 출력하고 입력했던 내용을 초기화합니다. 아직 객체지향을 배우지 않아 코드를 C 스타일로 작성했기때문에 가독성이 떨어질 수 있습니다. 양해 부탁드립니다.

## 2. 프로젝트 실행방법
### 1) Visual Studio 2022 버전을 설치합니다.

### 2)
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbEEYAt%2FbtrsrUd2mT7%2F0W0SAZbaWLOYRaYo5b20xk%2Fimg.jpg)

Clone a repository를 누릅니다.

### 3)
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fm0Ejc%2FbtrslWDXfRg%2Fa54Q36o0s4FdzkSUeJapwK%2Fimg.jpg)

Repository location에 https://github.com/psbnq/Cpp-Calculatior 를 입력하고, clone을 누릅니다.

### 4)
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F2oQLj%2FbtrssvdYdq5%2FPKKyesTTmv6KueQ7kAkysK%2Fimg.png)

실행 후 다음과 같은 화면이 나오기 전까지 기다리십시오. 

이제 main.cpp에서 ctrl + F5를 누르면 계산기 어플리케이션을 실행할 수 있습니다.

이러한 설치가 귀찮으시다면, exefile 디렉토리의 어플리케이션을 다운받으셔도 됩니다. x86과 x86-64(AMD)버전의 OS를 지원합니다.

## 3. 사용방법

포인터를 이동시켜 입력하는 방법과 키보드로 바로 입력하는 방법이 있습니다. 이 두가지 방법 모두 키보드를 이용합니다.

### 1) 포인터

|키|기능|
|:---:|:---:|
|←|포인터 왼쪽으로 이동| 
|↑|포인터 위로 이동|
|→|포인터 오른쪽으로 이동|
|↓|포인터 아래로 이동|
|SPACE|포인터 위치 누르기|

### 2) 키보드

|키|기능|
|:---:|:---:|
|[|'(' 입력|
|]|')' 입력|
|A|더하기(ADD)|
|D|나누기(DIVIDE)|
|S|빼기(SUBTRACT)|
|M|곱하기(MULTIPLY)|
|1~9|숫자입력|
|P|소수점(DECIMAL POINT)|
|ENTER|결과값 리턴|
|BACKSPACE|표현식 한자리 지우기|
|CLEAR|표현식 초기화|
|ESC|프로그램 종료|
