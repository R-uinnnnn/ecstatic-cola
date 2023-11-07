#pragma once
#include <assert.h>
using namespace std;
namespace abl
{
	template<class T>
	class vector
	{
	public:
			// Vector�ĵ�������һ��ԭ��ָ��
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

			}

			vector(int n, const T& value = T())
			{
				insert(n, value);
			}

			//template<class InputIterator>
			//vector(InputIterator first, InputIterator last)��

			//vector(const vector<T>& v)��

			//vector<T>& operator= (vector<T> v)��

			~vector()
			{
				if (_start != nullptr)//��Ϊ�գ��ͷſռ�
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
					//_end = _start + size();//��������⣬��Ϊ_start�Ѿ��ı䣬��_endû�б䣬���_start+_end-_start=_end=0;
					_end = _start + sz;
					_endofstorage = _start + n;
				}

			}

			void resize(size_t n, const T& value = T())//n>capacity,�ȸı�size�ָı�capacity��n<capacity��ֻ�ı�size
			{
				if (n < capacity())
				{
					if (n < size())
					{
						_end = _start + n;
					}
					else
					{
						cout <<"size:"<< size() << endl;
						cout << "capacity:" << capacity() << endl;
						size_t sz = size();
						for (size_t i = sz; i < n ; i++)
						{
							_start[i] = value;
						}
						_end = _start + n;
					}
				}
				else
				{
					reserve(n);
					//cout << "size:" << size() << endl;
					//cout << "capacity:" << capacity() << endl;
					size_t sz = size();
					for (int i = sz; i < n ; i++)
					{
						_start[i] = value;
					}
					_end = _start + n;
				}

								
				
			}
		 //   ///////////////access///////////////////////////////

			T& operator[](size_t pos)
			{
				return _start[pos];
			}

			const T& operator[](size_t pos)const
			{
				return _start[pos];
			}



			///////////////modify/////////////////////////////

			void push_back(const T& x)
			{
				if (capacity() > size())
				{
					_start[size()] = x;
					++_end;
				}
				else
				{
					size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
					reserve(newcapacity);
					_start[size()] = x;
					++_end;
				}
			}

			void pop_back()
			{
				--_end;
			}

			void swap(vector<T>& v)
			{
				std::swap(_start, v._start);
				std::swap(_end, v._end);
				std::swap(_endofstorage, v._endofstorage);
			}

			iterator insert(iterator pos, const T& x)
			{
				assert(pos >= _start && pos <= _end);//pos==_end�൱��β��
				if (size() == capacity())//�ռ����ˣ���Ҫ����
				{
					size_t sz = _end - _start;
					size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
					reserve(newcapacity);
					pos = _start + sz;//���ܳ��ֵ�����ʧЧ�����⣬pos����ָ��ԭ���ռ�
				}
				iterator it = _end;
				while (it != pos)
				{
					*it = *(it - 1);
					--it;
				}
				*pos = x;
				++_end;
				return pos;
			}

			iterator erase(iterator pos)
			{
				assert(pos >= _start && pos < _end);
				iterator it = pos+1;
				while (it != _end)
				{
					//*it = *(it + 1);
					*(it - 1) = *it;
					it++;
				}
				--_end;
				return pos;
			}
	private:
		iterator _start = nullptr;//��ʼ
		iterator _end = nullptr;//��β
		iterator _endofstorage = nullptr;//��������ĩβ

	};

}