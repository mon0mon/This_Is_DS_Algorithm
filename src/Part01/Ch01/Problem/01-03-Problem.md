## 연습문제

#### 03) 1장에서 구현한 리스트 예제 프로그램들은 노드 개수를 알아내는 방법이 굉장히 비효율적입니다.
#### 노드의 개수가 N개라면 N개의 루프를 수행해야 비로소 N을 알 수 있습니다.
#### 노드의 개수를 즉시 알아내는 방법이 없을까요? 다음 사항들을 중점으로 개선 방법을 생각해보고 설명하세요.

- 리스트 구조체 변경
- 삽입/삭제 연산 변경

#### 대답

```c
typedef struct TagNode
{
	ElementType data;
	struct TagNode* prev_node;
	struct TagNode* next_node;
	unsigned int node_count;
} Node;
```

TagNode 구조체에 `unsigned int` 형식의 `node_count`를 추가하여, 노드의 갯수를 저장할 수 있도록 수정했습니다.

\
이후에 삽입 삭제 연산이 발생 할 때마다 `head`의 `node_count`만 수정하는 방식으로 구현했습니다.
```c
void AppendNode(Node** head, Node* new_node)
{
	if ((*head) == NULL)
	{
		// 생략
	}
	else
	{
		// 생략
	}
	(*head).node_count++;
}
```

```c
void RemoveNode(Node** head, Node* remove)
{
	if ((*head) == remove)
	{
		// 생략
		// head가 NULL이므로 노드 갯수 연산 생략
	}
	else
	{
		// 생략
		(*head).node_count--;
	}
}
```
