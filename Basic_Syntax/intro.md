# Introducing C++

1. 외부 헤더파일을 추가하는 전처리자 (preprocessor) : #include

2. 표준 라이브러리 헤더파일 : <iostream>

3. namespace 내의 내용을 접근자 없이 사용 : using std::cout

4. 하나의 문장을 끝마치는 문자 : ;

5. 함수와 매개변수 그리고 모든 프로그램의 진입점인 main 함수 : int main(int argc, char* argv[])

6. 템플릿 클래스로 구현된 출력스트림의 전역 객체 : std::cout

7. 문자열 리터럴 : "Hello, world!"

8. 줄바꿈과 스트림 버퍼를 지우는 템플릿 함수 : std::endl

9. return 함수의 반환값 처리 : return

10. 값이 0인 매크로 : EXIT_SUCCESS


### if you know what below code means your good to go!


    #include <iostream>
    #include <string>

    // say what standard-library names we use
    using std::cin;         using std::endl;
    using std::cout;        using std::string;

    int main()
    {
        // ask for the person's name
        cout << "Please enter your first name: ";

        // read the name
        string name;
        cin >> name;

        // build the message that we intend to write
        const string greeting = "Hello, " + name + "!";

        // the number of blanks surrounding the greeting
        const int pad = 1;

        // the number of rows and columns to write
        const int rows = pad * 2 + 3;
        const string::size_type cols = greeting.size() + pad * 2 + 2;

        // write a blank line to separate the output from the input
        cout << endl;

        // write `rows' rows of output
        // invariant: we have written `r' rows so far
        for (int r = 0; r != rows; ++r) {

            string::size_type c = 0;

            // invariant: we have written `c' characters so far in the current row
            while (c != cols) {

                // is it time to write the greeting?
                if (r == pad + 1 && c == pad + 1) {
                    cout << greeting;
                    c += greeting.size();
                } else {

                    // are we on the border?
                    if (r == 0 || r == rows - 1 ||
                        c == 0 || c == cols - 1)
                        cout << "*";
                    else
                        cout << " ";
                    ++c;
                }
            }

            cout << endl;
        }

        return 0;
    }

## Coding Style

1. 변수, 함수 등 명명은 헝가리안 표기법

2. class, struct 는 대문자로 시작하고 함수객체를 FO 앞첨자, 클래스의 경우 뒷첨자로 Type

## 개발환경 

for Window : Visual Studio

for Mac : VS Code + g++ + lldb
