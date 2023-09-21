### VITAMIN QUIZ 1-1

#### `sizeof(Node)`와 `sizeof(Node*)`의 차이

- sizeof 연산은 주어진 인자가 메모리에서 얼마나 크기를 차지하고 있는지 연산자입니다.
- 보통 unsigned integer 형식으로 리턴합니다.

\

1. `sizeof(Node)`의 경우
    - 이 경우에는 `Node`가 인자로 전달되었기 때문에, `Node` 형식의 사이즈에 대해 리턴하게 됩니다.
    - 본문에서는 Node를 `ElementType`과 `struct TagNode *`를 포함하고 있기 때문에, `8Byte + 4Byte(패딩) + 4Byte(ElementType) = 16Byte`로 총 16Byte의 크기를 가집니다.
2. `sizeof(Node*)`의 경우
    - 이 경우에는 `Node*`가 인자로 전달되었기 때문에, `Node*` 형식의 사이즈에 대해 리턴하게 됩니다.
    - `struct TagNode *`를 포함하고 있기 때문에, `8Byte`로 총 8Byte의 크기를 가집니다.

__위 결과는 64비트 시스템에서 실행했을 때의 결과이므로, 32비트 시스템에서는 다른 결과가 나올 수 있습니다.__
