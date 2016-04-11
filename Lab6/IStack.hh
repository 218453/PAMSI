#ifndef IStack_HH
#define IStack_HH

/*! Interface describes the basic operations on the stack of different type. 
  User have to define type of the stack*/
template < typename type >
class IStack
{
public: 
	/*! 
	 * \brief Add element to the top of the stack.
	 * 
	 * \param[in] item - Item which will be added.
	 */
	virtual void Push(type item) = 0;
	
	/*!
	 * \brief Remove element from top of the stack and return it.
	 * 
	 * \return Item from top wich will be removed.
	 * \throw EmptyStackException when user tries to use this method on empty stack.
	 */
	virtual type Pop() = 0;
	
	/*!
	 * \brief Return item from top of the stack.
	 * 
	 * \return Item from top of the stack.
	 * \throw EmptyStackException when user tries to use this method on empty stack.
	 */
	virtual type Top() = 0;
	
	/*!
	 * \brief Return size of the stack.
	 * 
	 * \return Size of the stack.
	 */
	virtual int Size() = 0;
	
	/*!
	 * \brief Check whether the stack is empty
	 * 
	 * \return true - If stack is empty.
	 * \return false - If stack is not empty.
	 */
	virtual bool IsEmpty() = 0;
};

#endif