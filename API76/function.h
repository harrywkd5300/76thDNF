#pragma once


// Typedef
typedef unsigned int			_uint;
typedef signed int				_int;

template <typename T>
void safeDelete(T& obj)
{
	if(obj)
	{
		delete obj;
		obj = NULL;
	}
}

template <typename T>
bool CompareY(T& a, T& b)
{
	return a->GetRect().bottom < b->GetRect().bottom;
}

template <typename T>
void QuickSort(T& vec, _int iArr,  _int iLeft, _int iRight)
{
	if (0 == right)
		return;

	_int i, j, temp = 0;

	_int pivot = vec[iArr]->GetRect().bottom;

	if (left < right)
	{
		i = left + 1;
		j = right;

		while (i <= j)
		{
			while (vec[i].->GetRect().bottom < pivot)
				i++;
			while (vec[j]->GetRect().bottom > pivot)
				j--;

			if (i < j)
			{
				temp = vec[i]->GetRect().bottom;
				vec[i]->GetRect().bottom = vec[j]->GetRect().bottom;
				vec[j]->GetRect().bottom = temp;
			}
			else
				break;
		}

		temp = vec[j]->GetRect().bottom;
		vec[j]->GetRect().bottom = vec[left]->GetRect().bottom;
		vec[left]->GetRect().bottom = temp;

		QuickSort(vec, left, j - 1);
		QuickSort(vec, j + 1, right);
	}
}
