#include <stdio.h>  

int main(void)
{
    printf("Hello world!\n");
    return 0;
}


// clang -std=c89 -W -Wall -pedantic-errors  // flag 확인해야함
// a.out
// echo $?  // 0


// #include 는 preprocessor(전처리기) 지시문 중 하나
// preprocessor란;
// 직역: processor: 처리해주는 것 , pre: 전에 ; 실제 처리하기 전에 뭔가 해주는 것
// 1. 컴파일 하기 전에 텍스트를 '복붙'해주는 일을 함
// 2. 자세한 부분은 나중에 추가 (컴파일, 링킹 파트에서 정확히 알 수 있음)

// <> 안의 단어(예: stdio.h)는 실제 디스크 상에 존재하는 파일이름


// #include <stdio.h>  
// 라이브러리에서 찾아서 쓸게~ 이런게 아니라 
// 해당 파일 찾아서 '포함'해줘라

// 여기서 '포함'이란?
// (간단한 설명; 메모리 상에서 일어나는 일)
// stdio.h 파일을 열어 내용을 복사
// #include <stdio.h> 을 지우고 복사한 내용으로 바꿈

// #include <stdio.h>
// #include 'stdio.h' 컴파일 안됌
// #include "stdio.h" 컴파일 되지만 , 일단 사용하지 말 것; stdio에 한해서는! 

// stdio.h 표준 입출력을 담당
// 스트림 입출력에 관련된 함수들을 포함




// main(void) 함수
// 프로그램 entry point(진입점)
// C 코드를 빌드해서 나온 실행파일(.exe 또는 .out)을 실행하면 main(void) 함수가 자동적으로 실행됌

// int main()
// void 매개변수 생략도 가능하다 하지만,,,
// 설명: 표준이 약간 모자란 부분이라고 생각하고 넘어가자
// 다른 언어와 달리 void를 생략한다고 매개변수가 없다는 뜻이 아님
// C 에는 '함수 선언' 그리고 '함수 정의'가 분리된 개념임
// - '함수 선언': void를 생략하면 매개변수를 받는다는 의미; 단, 아직 매개변수의 갯수와 자료현을 모른다는 뜻
// - '함수 정의': void를 생략하면 매개변수가 없다는 의미
// 따라서, 언제나 void를 넣는 습관을 기르자

// 함수 선언, 정의 -> 중괄호 유무로 구분됌 (그리고 세미콜론 정도?)

// - '함수 선언':
// int sum(void);    // 매개변수 없음

// int sum();        // 매개변수 있음; 아직 뭔지 모름

// - '함수 정의':
// int sum(void)     // 매개변수 없음
// {

// }

// int sum()         // 매개변수 없음
// {

// }

// int sum(const int num1, const int num2)    // 매개변수 2개 있음
// {

// }