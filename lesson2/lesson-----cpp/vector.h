#pragma once

using namespace std;
namespace abl
{
	template<class T>
	class vector
	{
	public:
			// Vector的迭代器是一个原生指针
			typedef T* iterator;
			typedef const T* const_iterator;
			iterator begin()
			{
				return _start;
			}

			iterator end()
			{
				return _end;
			}

			const_iterator cbegin()
			{
				return _start;
			}

			const_iterator cend() const
			{
				return _end;
			}
			// construct and destroy

			vector()
			{
				_start = new T;
				*_start = 1;
				_end=_endofstorage = _start + 1;

			}

			vector(int n, const T& value = T())
			{
				insert(n, value);
			}

			//template<class InputIterator>
			//vector(InputIterator first, InputIterator last)；

			//vector(const vector<T>& v)；

			//vector<T>& operator= (vector<T> v)；

			~vector()
			{
				if (_start != nullptr)//不为空，释放空间
				{
					delete[] _start;
					_start = _end = _endofstorage = nullptr;
				}

			}
			// capacity
			size_t size()
			{
				return _end - _start;
			}
			size_t size() const
			{
				return _end - _start;
			}
			size_t capacity()
			{
				return _endofstorage - _start;
			}
			size_t capacity() const
			{
				return _endofstorage - _start;
			}

			void reserve(size_t n)
			{
				if (n > capacity())
				{
					T* tmp = new T[n];
					int sz = size();
					for (int i = 0; i < size(); i++)
					{
						tmp[i] = _start[i];
					}
					delete _start;
					_start = tmp;
					//_end = _start + size();//会出现问题，因为_start已经改变，而_end没有变，因此_start+_end-_start=_end=0;
					_end = _start + sz;
					_endofstorage = _start + n;
				}

			}

			//void resize(size_t n, const T& value = T())
			//{

			//}
		 //   ///////////////access///////////////////////////////

			//T& operator[](size_t pos)；

			//const T& operator[](size_t pos)const；



			///////////////modify/////////////////////////////

			//void push_back(const T& x)；

			//void pop_back()；

			//void swap(vector<T>& v)；

			//iterator insert(iterator pos, const T& x)；

			//iterator erase(Iterator pos)；
	private:
		iterator _start = nullptr;//开始
		iterator _end = nullptr;//结尾
		iterator _endofstorage = nullptr;//数据容量末尾

	};

}