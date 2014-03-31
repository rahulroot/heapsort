/* A HeapSort */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

using namespace std;

int heapsize = 0;
int *a = NULL;
int maxnum = 0;

void print_heap(int *a)
{
	cout <<"Debugging print... ";
	for(int i = 1; i <= maxnum; ++i)
		cout << a[i] <<" ";
	cout << endl;
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/* ugly function, need to modify */
int find_min(int lc, int rc, int pos)
{
	int lmin = pos;
	if(lc <= maxnum)
	{
		if(a[lc] < a[pos])
			lmin = lc;
	}
	int rmin = pos;
	if( (rc <= maxnum))
	{
		if(a[rc] < a[pos])
			rmin = rc;
	}
	int cmin = 0;
	if( (lc <= maxnum) && (rc <= maxnum))
	{
		if(a[lc] < a[rc])
			cmin = lc;
		else
			cmin = rc;
	}
	int min = 0;
	if(a[lmin] < a[rmin])
	{
		if(a[lmin] < a[pos])
			min = lmin;
		else
			min = pos;
	}
	else
	{
		if(a[rmin] < a[pos])
			min = rmin;
		else
			min = pos;
	}
	
	return min;

}

/* Re arrange the element in heap corresponds to min heap or max heap */
void heapify(int *a, int pos)
{
	int lc = 2*pos;
	int rc = 2*pos + 1;
	int min = find_min(lc, rc, pos);
	if ( min != pos)
	{
		swap(a[min], a[pos]);
		heapify(a, min);
	}
}

void decrease_key(int p, int delta)
{
	if(p <= maxnum)
	{
		a[p] = a[p]-delta;
		for(int i = p; i > 0; i = floor(i/2))
			heapify(a, i);
	}
	else
		cout <<"Invalid Heap Location." << endl;

}

void increase_key(int p, int delta)
{
	if(p <= maxnum)
	{
		a[p] = a[p]+delta;
		heapify(a, p);
	}
	else
		cout <<"Invalid Heap Location." << endl;
}

void remove(int p)
{
	if( p <= maxnum)
	{
		swap(a[p], a[maxnum]);
		maxnum--;
		heapify(a, 1);
	}
	else
		cout <<"Invalid Heap Location." << endl;
}

/* size of a or heap will be determined from heapsize */
int delete_min(int *a)
{
	swap(a[1], a[maxnum]);
	int tmp = a[maxnum];
	maxnum--;
	heapify(a, 1);
	return tmp;
	
}

/* Array is already populated with rand() element, we just
 * need to shift element to 1 right position in array.*/

void build_heap(int *a, int num)
{
	for(int i = num; i > 0; --i)
		a[i] = a[i-1];
	for(int i = floor(num/2); i > 0; --i)
		heapify(a, i); 
}


void heap_sort(int *a)
{
	int i = maxnum;
	while(i > 0)
	{
		swap(a[1], a[i]);
		maxnum--;
		cout << a[i] <<" ";
		heapify(a, 1);
		i--;
	}
}


int main(int argc, char **argv)
{
	if(argc < 2 )
	{
		cout <<"Usage : ./a.out no_of_records." << endl;
		cout <<"Usage : ./a.out 2000 " << endl;
		exit(-1);
	}
	
	maxnum = atoi(argv[1]);
	a = new int[maxnum+1];
	if(!a) {
		cout <<" Insufficient Memory. " << endl;
		exit(-1);
	}

	int lb = 0, ub = maxnum - 1;
	for(int i = lb; i <= ub; ++i)
	{
		a[i] = rand()%maxnum;
	}
	
	cout <<"Original Array. ";
	for(int i = 0; i < maxnum; ++i)
		cout << a[i] <<" ";
	cout << endl;

	build_heap(a, maxnum);
	cout<<"Min Build heap ... "; 
	print_heap(a);

	cout <<"Increasing key of position 2 by 4. ";
	increase_key(2, 4);
	print_heap(a);
	cout <<"Increasing key of position 3 by 7. ";
	increase_key(3, 7);
	print_heap(a);

	cout <<"Decreasing key of position 4 by 1. ";
	decrease_key(4, 1);
	print_heap(a);
	cout <<"Decreasing key of position 5 by 1. ";
	decrease_key(5, 5);
	print_heap(a);

	cout <<"After removing element at 1st position. ";
	remove(1);
	print_heap(a);

	cout <<"After Sorting..." << endl;
	
	heap_sort(a);
	cout << endl;

	delete [] a;
	
	return 0;
}
