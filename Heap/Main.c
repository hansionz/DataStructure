#include "Heap.h"

void TestHeap()
{
	Heap h;
	HTDataType arr[] = { 17, 18, 68, 28, 54, 87 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	HeapInit(&h, arr, size); 
	PrintHeap(&h);
	HeapPush(&h, 100);
	PrintHeap(&h);
	HeapPop(&h);
	PrintHeap(&h);
	printf("堆的大小为：%d\n", HeapSize(&h));
	printf("？空(空:0,非空:1):%d\n", HeapEmpty(&h));
	printf("堆顶元素为:%d\n", HeapTop(&h));
	HeapDestory(&h);
}
int main()
{
	TestHeap();
	system("pause");
	return 0;
}