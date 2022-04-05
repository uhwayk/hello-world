/**************************************
*  Multi-Include-Prevent Section
**************************************/

#ifndef SORT_H_INCLUDE
#define SORT_H_INCLUDE

/***************************************
*	Prototype Declare Section
***************************************/

/**
 *  @name        : void InsertSort(int a[], int n)
 *	@description : Insert the data into the sorted table one by one in a certain order, and the final sequence is the sorted data.
 *	@param		 : int a[], int n
 *	@return		 : void
 *  @notice      : None
 */
void InsertSort(int a[], int n);

/**
 *  @name        : void merge(int a[],int l,int r,int mid)
 *	@description :
 *	@param		 : int a[], int n
 *	@return		 : void
 *  @notice      : None
 */
void merge(int a[],int l,int r,int mid);

/**
 *  @name        : void merge_sort(int a[],int l,int r)
 *	@description :
 *	@param		 : int a[], int n
 *	@return		 : void
 *  @notice      : None
 */
void merge_sort(int a[],int l,int r);

/**
 *  @name        : MergeSort(int a[],int l,int r);
 *	@description :
 *	@param		 : int a[], int n
 *	@return		 : void
 *  @notice      : None
 */
void MergeSort(int a[],int l,int r);

/**
 *  @name        : void CountSort(int a[],int n)
 *	@description : Counting sorting is not a comparison-based sorting algorithm, and its core is to convert the input data values ​​into keys and store them in the additionally opened array space. As a sort of linear time complexity, counting sort requires that the input data must be an integer with a certain range.
 *	@param		 : int a[], int n
 *	@return		 : void
 *  @notice      : None
 */
//void CountSort(int a[],int n);

/**
 *  @name        : void Quick_Sort(int *arr, int begin, int end)
 *	@description :
 *	@param		 : int *arr, int begin, int end
 *	@return		 : void
 *  @notice      : None
 */
void QuickSort(int *arr, int begin, int end);

/**
 *  @name        : void CountSort(int *a, int len)
 *	@description :
 *	@param		 : int *a, int len
 *	@return		 : void
 *  @notice      : None
 */
void CountSort(int *a, int len);

/**
 *  @name        : void RadixSort(int *a, int length)
 *	@description :
 *	@param		 : int *a, int len
 *	@return		 : void
 *  @notice      : None
 */
void RadixSort(int *a, int length);

#endif // SORT_H_INCLUDE
