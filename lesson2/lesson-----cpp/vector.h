#pragma once


namespace abl
{
	template<class T>
	class vector
	{
	public:
			// Vector的迭代器是一个原生指针
			typedef T* iterator;
			typedef const T* const_iterator;
			iterator begin()；

			iterator end()；

			const_iterator cbegin()；

			const_iterator cend() const；
			// construct and destroy

			vector()；

			vector(int n, const T& value = T())；

			template<class InputIterator>

			vector(InputIterator first, InputIterator last)；

			vector(const vector<T>& v)；

			vector<T>& operator= (vector<T> v)；

			~vector()；
			// capacity

			size_t size() const ；

			size_t capacity() const；

			void reserve(size_t n)；

			void resize(size_t n, const T& value = T())；
		    ///////////////access///////////////////////////////

			T& operator[](size_t pos)；

			const T& operator[](size_t pos)const；



			///////////////modify/////////////////////////////

			void push_back(const T& x)；

			void pop_back()；

			void swap(vector<T>& v)；

			iterator insert(iterator pos, const T& x)；

			iterator erase(Iterator pos)；
	private:
		iterator _start = nullptr;//开始
		iterator _finish = nullptr;//结尾
		iterator _endofstorage = nullptr;//数据容量末尾

	};
}