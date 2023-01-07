### 7.2

![](E:\FuDan University\2022秋\数据结构\HomeWork\HW7\IMG_20221204_155610.jpg)
$$
ASL_{succ} = \frac{1}{14} {\textstyle \sum_{0}^{13}(n + 1)} = \frac{15}{2} \\
ASL_{unsucc} = \frac{1}{15} (14 + {\textstyle \sum_{1}^{14}n}) = \frac{119}{15}
$$

### 7.3

![](E:\FuDan University\2022秋\数据结构\HomeWork\HW7\IMG_20221204_155635.jpg)
$$
ASL_{succ} = \frac{1}{14} (1\times 1+2\times 2+4\times 3+7\times 4) = \frac{45}{14} \\
ASL_{unsucc} = \frac{1}{15} (1\times 3+14\times 4) = \frac{59}{15}
$$

### 7.4

#### (1)

不同。有序顺序表的平均搜索长度
$$
ASL_{unsucc} = \frac{1+2+\cdots +n+n}{n+1} =\frac{n}{2}+\frac{n}{n+1}
$$
无序顺序表的平均搜索长度
$$
ASL_{unsucc} = n
$$

#### (2)

相同。有序顺序表和无序顺序表的平均搜索长度
$$
ASL_{succ} = \frac{1+2+\cdots +n}{n} =\frac{n+1}{2}
$$

#### (3)

不同。假设关键码值为k的元素有m个，有序顺序表的平均搜索长度
$$
ASL_{succ} = \frac{1+2+\cdots +(n-m+1)}{n-m+1}+(m-1) =\frac{n+m}{2}
$$
无序顺序表的平均搜索长度
$$
ASL_{succ} = n
$$

### 7.14

#### (1)

![](E:\FuDan University\2022秋\数据结构\HomeWork\HW7\CamScanner 12-04-2022 18.32.jpg)

#### (2)

$$
ASL_{succ} = \frac{1}{9} (1\times 1+2\times 2+4\times 3+2\times 4) = \frac{25}{9} \\
ASL_{unsucc} = \frac{1}{10} (6\times 3+4\times 4) = \frac{17}{5}
$$

### 7.28

```c++
template <class T>
void BSTree<T>::Remove(T x, BSTreeNode<T>*& ptr) {
	if (ptr == NULL) return;
	if (x < ptr->data) Remove(x, ptr->leftChild);
	else if (x > ptr->data) Remove(x, ptr->rightChild);
	else if (ptr->leftChild != NULL && ptr->rightChild != NULL) {
		srand((unsigned)time(NULL));
		if (rand() % 2) {
			BSTreeNode<T>* temp = ptr -> leftChild;
			while (temp->rightChild != NULL) temp = temp->rightChild;
			ptr->data = temp->data;
			Remove(ptr->data, ptr->leftChild);
		}
		else {
			BSTreeNode<T>* temp = ptr->rightChild;
			while (temp->leftChild != NULL) temp = temp->leftChild;
			ptr->data = temp->data;
			Remove(ptr->data, ptr->rightChild);
		}
	}
	else {
		BSTreeNode<T>* temp = ptr;
		ptr = (ptr->leftChild != NULL) ? ptr->leftChild : ptr->rightChild;
		delete temp;
	}
}
```
