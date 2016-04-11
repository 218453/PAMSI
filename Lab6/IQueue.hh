#ifndef IQueue_HH
#define IQueue_HH

/*! Interface describes the basic operations on the queue of different type. 
  User have to define type of the queue*/
template < typename type >
class IQueue
{	
public: 
	/*!
	 * \brief Add element to the end of the queue.
	 * 
	 * \param[in] item - Item which will be added.
	 */
	virtual void Enqueue(type item) = 0;
	
	/*!
	 * \brief Remove element from the beginning of the queue and return it.
	 * 
	 * \return Item which will be removed.
	 * \throw EmptyQueueException when user tries to use this method on empty queue.
	 */
	virtual type Dequeue() = 0;
	
	/*!
	 * \brief Return element from the beginning of the queue.
	 * 
	 * \return Item  from the top of the queue.
	 * \throw EmptyQueueException when user tries to use this method on empty queue.
	 */
	virtual type Front() = 0;
	
	/*!
	 * \brief Return size of the queue.
	 * 
	 * \return Size of the queue.
	 */
	virtual int Size() = 0;
	
	/*!
	 * \brief Check whether the queue is empty
	 * 
	 * \return true - If queue is empty.
	 * \return false - If queue is not empty.
	 */
	virtual bool IsEmpty() = 0;
};

#endif