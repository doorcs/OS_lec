#include <stdarg.h> // va_list, va_start(), va_arg(), va_end()
// #include <stdio.h> // printf()

// main함수의 가변 인자 리스트와 구조적으로 비슷함
void vaFunc(int argc, ...) { // `argc` = argument count  `...` = argument vector (undetermined)
    va_list vp;
    va_start(vp, argc); // `va_list vp` init

    for (int i = 0; i < argc; i++) {
        /*
         * return && pointer increment
         * va_arg(va_list, type) 함수는 `va_list`에서부터 자료형 크기만큼의 바이트를 읽어들여 return하고, `va_list`를 자료형 크기만큼 increment (다음 요소를 가리킬 수 있도록)
         */

        // int a = va_arg(vp, int); // vp에서 sizeof(int)만큼의 바이트를 읽어서 return하고, vp를 `sizeof(int)` 바이트만큼 increment

        // do something with `a`
        // example: `printf("%d ", a);`
    }
    va_end(vp); // memory cleanup
} // printf() 함수는 매 호출마다 파라미터들을 동적으로 관리해야 하기 때문에, 구현에 va_list, va_start, va_arg, va_end 등이 사용됨!

int main(int argc, char* argv[]) { // main함수에 전달되는 argc, argv[]는 <stdarg.h> 헤더의 va_list를 쓰지 않는다! executable 실행시에 `정확히` 결정되는 값들이며, 운영체제가 설정해준다
    vaFunc(1, 3);
    vaFunc(2, 3, 6);
    vaFunc(3, 3, 6, 9);
    vaFunc(4, 3, 6, 9, 12);
}

// https://stackoverflow.com/questions/40484293/stdarg-and-printf-in-c
// `#include <stdio.h>` 를 했더라도, va_list를 쓰려면 `#include <stdarg.h>`를 써줘야 하는 이유
