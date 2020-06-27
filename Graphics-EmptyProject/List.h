#pragma once
template <class T>
struct TNode
{
	T val;   //�������� �����
	TNode<T> *pNext;  //��������� �� ��������� �����
};
template <class T>
class TList
{
protected:
	TNode<T> *pFirst; //��������� �� ������ �����
	TNode<T> *pLast;  //��������� �� ���������
	TNode<T> *pCurr;  //��������� �� �������
	TNode<T> *pPrev;  //��������� �� ����������
	TNode<T> *pStop;  //���������, ���������� ����� ������
	int len;          //���������� ������� � ������
	int pos;          //����� ������� �������
public:
	TList(); //�����������
	~TList(); //����������
	void DelList(); //�������� ������
	//������
	int GetSize() { return len; } //���-�� ��������� � ������
	T GetCurr();   //������� ��������
	//���������
	void InsFirst(T el); //����� ������
	void InsCurr(T el);  //����� �������
	void InsLast(T el);  //���������
	void InsOrder(T el); //�� ������� 
	//��������
	void DelFirst(); //������� ������ �����
	void DelCurr();  //������� ������� �����
	void DelLast();  //������� ��������� �����
	//���������
	int GetPos() { return pos; } //����� ������� �������
	void SetPos(int _pos);  //���������� ������� �����
	void Reset();  //���������� �� ������ �����
	void GoNext(); //���������� �� ���������
	bool IsEnd();  //������ ��������?
	//�����
	friend ostream& operator<<(ostream &out, TList<T> &l)
	{
		for (l.Reset(); !l.IsEnd(); l.GoNext())
			out << l.pCurr->val << ' ';
		return out;
	}
	
};
template<class T>
TList<T>::TList()
{
	len = 0;
	pos = -1;
	pFirst = NULL;
	pLast = NULL;
	pCurr = NULL;
	pPrev = NULL;
	pStop = NULL;
}
template<class T>
void TList<T>::DelList()
{
	TNode<T> *tmp = pFirst;
	//if (tmp == pStop)
		//delete tmp;
	while (pFirst != pStop) {
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}

	TNode<T> *p;
	p = pFirst;
	while (pFirst != pStop)
	{
		pFirst = pFirst->pNext;
		delete p;
		p = pFirst;
	}
}
template<class T>
TList<T>::~TList()
{
	DelList();
}
template<class T>
void TList<T>::SetPos(int _pos)
{
	Reset();
	for (int i = 0; i < _pos; i++)
		GoNext();
}
template<class T>
void TList<T>::InsFirst(T el)
{
	TNode<T> *pNewFirst = new TNode<T>;
	pNewFirst->val = el;
	if (pFirst == pStop)
	{
		pFirst = pLast = pCurr = pNewFirst;
		pFirst->pNext = pStop;
		pos = 0;
	}
	else
	{
		pNewFirst->pNext = pFirst;
		pFirst = pNewFirst;
	}
	len++;
}
template<class T>
void TList<T>::InsLast(T el)
{
	if (pFirst == pStop) InsFirst(el);
	else
	{
		TNode<T> *pNew = new TNode<T>;
		pNew->val = el;
		pLast->pNext = pNew;
		pLast = pNew;
		pLast->pNext = pStop;
		len++;
	}
}
template<class T>
void TList<T>::DelLast()
{
	if (pLast == pFirst) DelFirst();
	else
	{
		for (Reset(); pCurr->pNext != pStop; GoNext()) {}
		delete pLast;
		pLast = pPrev;
		pCurr = pPrev;
		pCurr->pNext = pStop;
		len--;
		Reset();
	}

}
template<class T>
void TList<T>::DelFirst()
{
	TNode<T> *p = pFirst;

	if (len == 1)
	{
		pos = -1;
		delete p;
		pFirst = pCurr = pLast = pPrev = pStop;
	}
	else
	{
		pFirst = pFirst->pNext;
		pCurr = pCurr->pNext;
		delete p;
		pos--;
	}
	len--;
}
template<class T>
void TList<T>::InsCurr(T el)
{
	if (pCurr == pFirst)
	{
		InsFirst(el);
		pCurr = pFirst;
	}
	else
	{
		TNode<T> *pNew = new TNode<T>;
		pNew->val = el;
		pPrev->pNext = pNew;
		pNew->pNext = pCurr;
		pCurr = pNew;
		len++;
	}
}
template<class T>
void TList<T>::DelCurr()
{
	if (pCurr == pStop) return;
	if (pCurr == pFirst) DelFirst();
	else
	{
		pPrev->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pPrev->pNext;
		len--;
	}
}
template<class T>
T TList<T>::GetCurr()
{
	return pCurr->val;
}
template<class T>
void TList<T>::Reset()
{
	pCurr = pFirst;
	pos = 0;
	pPrev = NULL;
}
template<class T>
void TList<T>::GoNext()
{
	pPrev = pCurr;
	pCurr = pCurr->pNext;
	pos++;
}
template<class T>
bool TList<T> ::IsEnd()
{
	if (pCurr == pStop) return true;
	else return false;
}
template<class T>
void TList<T>::InsOrder(T el)
{
	if (pFirst->val < el) InsFirst(el);
	if (pLast->val > el) InsLast(el);
	else
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			if (pCurr->val < el)
				InsCurr(el); break;
		}
	}
}

