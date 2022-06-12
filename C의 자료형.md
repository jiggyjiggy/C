https://en.wikipedia.org/wiki/C_data_types

primitive types (기본 자료형)

char 
short 
int 
long
float 
double 
long 
double

!!!! 중요
어떤 자료형을 얘기 할때는 
딱 "몇 바이트야" 라고 말하는 기준자체가 애매한 자료형이 있다
해당 부분은 "표준" 자체에서 잘 얘기를 안해 놓은 것임 ; ex: char



unsigned 와 signed
unsigned 라는 단어를 자료형 이름앞에 넣어줘야 함
    - unsigned char, unsigned int 

    - '부호 있음'을 명확하게 보여주기 위해서 signed 를 붙일 수도 잇음 (하지만 생략 가능)
        - signed char, signed int

    - unsigned / signed 를 생략하면 '부호 있음(signed)' 이 기본
        - 예외: char  ; C에서 character 는 1바이트 짜리 정수임 (1바이트: 컴퓨터에서 데이터를 '읽어오는' 가장 작은 단위)


코드 예시 

char default_char = 100;
signed char signed_char = -100;
unsigned char unsigned_char = 255;

int default_int = -10000;
signed int signed_int = -10000;
unsigned int unsigned_int = 234545;



char ch_a = 'a';
char ch_b = ch_a + 1; /* b */
char ch_c = 99;       /* c */

표준에서 char는 1바이트라고 정의하고 있지 않음

표준은 8비트 이상 이라고만 정의하고있음! 
바꿔 말하면, "나는 char를 1백만 비트로 만들꺼야" 라고 해도 표준에 맞음 
(= 컴파일러 멋대로 1백만 비트도 가능하다)
    - 어떤 컴파일러를 사용하느냐에 따라 char가 8비트 일 수 도 있고, 16비트 일 수 도 있고, 9비트 일수도 있고

-> 모든 내용을 종합해보자면 = char는 최소 8비트인 정수형
 


 그렇다면 char가 몇 비트인지 찾는 방법은? 

 <limits.h> 헤더를 인클루드 한 뒤,
 CHAR_BIT를 보면 몇 비트인지 알수 있음

 참고로 C 표준은 기본 자료형의 정확한 바이트 수를 강요하지 않는다 ; 각 컴파일러마다 알아서 하라고 한다
 더 나아가 1바이트를 CHAR_BIT 만큼이라고 말함! 
    -> 1바이트는 비트 8개가 모인것; 보통 다른 언어에서는 이럼
    -> 그러나 C에서는 1바이트가 8비트가 아닐 수 있다
        - C에서는 CHAR_BIT이 8비트면 그게 1바이트이고, 16비트면 그게 1바이트 이다

char 라는 것은 내가 돌리는 기계에서 표현 할 수 있는 가장 작은 단위의 메모리!
내가 접근하고 데이터를 저장하는 단위의, 가장 작은 메모리
그게 어떤 기계에서는 1바이트 일 수도 있고, 어떤 기계에서는 2바이트 일 수도 있음
    -> 일반적으로는 8비트로 저장, 16바이트로 저장; 이게 char 라는 것임 
    -> 그러므로 C에서 바이트라고 하는 개념은, char의 크기이다; 지금 사용하고 있는 기계에 가장 작은 단위
    -> 그 단위가 16비트라면, 16비트가 1바이트이다. 그리고 그 1바이트가 char의 사이즈 인 것.

왜? 소형기기에 따라 특정 크기를 사용하는게 어려울 수도



char와 ASCII문자

정수형
char는 ASCII 문자를 표현하기에 충분; ASCII는 0~127 인 숫자
8비트에서 맨 앞 비트(최 상위 비트)는 부호



char와 signed / unsigned

정수형이니 signed 와 unsigned 가 있음
signed / unsigned를 생략하면 ; 보통 signed라고 생각하지만

C 표준은 그런걸 정하지 않았기에, 컴파일러마다 다르다

clang, 윈도우 기준으로 signed 이다




char 의 기본 부호가 지정 안된 이유?

- ASCII의 범위는 0~127 이므로 부호여부는 상관이 없음
- 단, 8비트 정수형으로 쓰려고 할때는
반드시 char 앞에 signed 나 unsigned를 넣어주는 게 좋음

signed char signed_char = -1;
unsigned char unsigned_char = 255;

- 안 그러면 포팅해도 문제없는 정수 범위는 0~127 사이 뿐이다!




char의 부호 여부를 판단하는 방법은?

- <limits.h> 헤더 파일에서 CHAR_MIN을 보면 부호 식별자가 없는 char 가 signed 인지 unsigned 인지 알 수 있다




char로 표현 가능한 숫자의 범위 (표준)

- 포팅 문제 없는 범위
unsigned char : 0~255
char          : 0~127
signed char   : -127~127

-> signed char가 뭔가 수상하다 수상해!
왜 -128이 아니라 -127인걸까?
    - 1의 보수 : (1의 보수 시스템에서는 +0, -0 존재)
        - 아주아주 옛날 기계는 1의 보수를 쓸수도 있음
        - 그러나 이제 그런 기계는 거의 없음
        - 그래도 '안전한' 포팅을 위해서는 -128이 아니라 -127
    ;포팅 문제 없는 범위는 1의 보수를 얘기하는 것임!
    2의 보수가 되는 순간 -128~127인데, 1의 보수를 지원하는 기계용으로 컴파일하면 -128이 사라짐




char로 표현 가능한 숫자의 범위 (보통)

표준은 표준이고,,,

실제 보통(데스크톱 개발 시) 안전하게 생각해도 되는것
    1. 크기: 8비트
    2. 부호(unsigned / signed)를 생략할 경우: signed 
        char signed_char = -1;
    3. 범위
        부호 없는 경우(unsigned) : 0~255
        부호 있는 경우(signed) : -128~127




quiz
1. 
Q. C 표준에 따르면 char 형의 크기는?
A. 최소 8비트

2. 
Q. signed/unsigned 가 생략된 char 형에 대해 옳은 설명
A. C 표준은 signed/unsigned 가 생략된 char 형이 signed 인지, unsigned 인지에 대해 정의하지 않으며, 이것은 컴파일러 구현에 따라 달라진다.

3.
Q. C 표준에 따르면 signed char로 표현 가능한 숫자의 범위는?
A. -127 ~ 127

4. 
Q. C 표준에 따르면 unsigned char로 표현 가능한 숫자의 범위는?
A. 0 ~ 255


------------------------------------------------------------------------------