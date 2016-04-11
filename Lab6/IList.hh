#ifndef IList_HH
#define IList_HH

/*! Interface describes the basic operations on the list of different type. 
  User have to define type of the list*/
template < typename type >
class IList
{
public:
	/*!
	 * \brief Add element to list at specific place(index)
	 * 
	 * \param[in] item - Item which will be added.
	 * \param[in] index - specific place on the list for new item.
	 * 
	 * \throw IndexOutOfRangeException when user tries to use this method on a non-existent index.
	 */
	virtual void Add(type item, int index) = 0;
	
	/*!
	 * \brief Add element to list at a given index
	 * 
	 * \param[in] item - Item which will be added.
	 * \param[in] index - index on the list for new item.
	 * 
	 * \throw IndexOutOfRangeException when user tries to use this method on a non-existent index.
	 */
	virtual void Remove(int index) = 0;
	
	/*!
	 * \brief Return value of the element at given index.
	 * 
	 * \return Value of the element at given index.
	 * \throw IndexOutOfRangeException when user tries to use this method on a non-existent index.
	 */
	virtual type Get(int index) = 0;
	
	/*!
	 * \brief Return size of the list.
	 * 
	 * \return Size of the list.
	 */
	virtual int Size() = 0;
	
	/*!
	 * \brief Check whether the list is empty
	 * 
	 * \return true - If list is empty.
	 * \return false - If list is not empty.
	 */
	virtual bool IsEmpty() = 0;
	
};

#endif