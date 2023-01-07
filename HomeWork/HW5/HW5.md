### 5.20

首先针对它们建立Huffman树

![](E:\FuDan University\2022秋\数据结构\HomeWork\HW5\CamScanner 11-12-2022 00.10.jpg)

Huffman编码为

|  c1  |  c2  |  c3  |  c4  |  c5  |  c6  |  c7  |  c8  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| 0110 |  10  | 0000 | 0111 | 001  | 010  |  11  | 0001 |

电文总码数为
$$
4 \times 5+2 \times 25+4 \times 3+4 \times 6+3 \times 10+3 \times 11+2 \times 36+4 \times 4=257
$$

### 5.23

#### (1)

```c++
template<class T>
int leaves(BinTreeNode<T>* t) const {
	if (t == NULL) return 0;
	if (t->leftChild == NULL && t->rightChild == NULL) return 1;
	return leaves(t->leftChild) + leaves(t->rightChild);
}
```

#### (2)

```c++
template<class T>
void exchange(BinTreeNode<T>* t) {
	if (t == NULL) return;
	BinTreeNode<T>* temp = t->leftChild;
	t->leftChild = t->rightChild;
	t->rightChild = temp;
	exchange(t->leftChild);
	exchange(t->rightChild);
}
```

### 5.29

```c++
template<class T>
void BinTree_Link_to_Array(BinTreeNode<T>* t, T a[], int n, int i)
{
	if (t == NULL) return;
	if (i < n)
	{
		a[i] = t->data;
		BinTree_Link_to_Array(t->leftChild, a, n, 2 * i + 1);
		BinTree_Link_to_Array(t->rightChild, a, n, 2 * i + 2);
	}
	else {
		cerr << "Subscript out of range" << endl;
		exit(1);
	}
}
```

### 5.33

#### (1)

```c++
template<class T>
struct LsRcNode {
	T data;
	int llink, rlink;
};

template<class T>
struct DblTagNode {
	T data;
	int ltag, rtag;
};

template<class T>
class LsRcTree
{
private:
	LsRcNode<T>* LsRcList;
	DblTagNode<T>* DblTagList;
	int MaxSize, CurrentSize;
public:
	LsRcTree(int size) :MaxSize(size), CurrentSize(0) {
		LsRcList = new LsRcNode<T>[size];
		DblTagList = new DblTagNode<T>[size];
		assert(LsRcList != NULL && DblTagList != NULL);
	}
};
```

#### (2)

```c++
template<class T>
void LsRcTree<T>::DblTag_to_LsRc()
{
	stack<int> s;
	for (int i = 0; i < CurrentSize; i++) {
		if (DblTagList[i].ltag == 0) {
			if (DblTagList[i].rtag == 0) {
				LsRcList[i].llink = LsRcList[i].rlink = -1;
				int k = s.top();
				s.pop();
				LsRcList[k].rlink = i + 1;
			}
			else {
				LsRcList[i].llink = -1;
				LsRcList[i].rlink = i + 1;
			}
		}
		else {
			if (DblTagList[i].rtag == 0) {
				LsRcList[i].llink == i + 1;
				LsRcList[i].rlink == -1;
			}
			else {
				LsRcList[i].llink = i + 1;
				s.push(i);
			}
		}
	}
}
```

