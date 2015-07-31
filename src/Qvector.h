#ifndef QVECTOR_H_INCLUDED
#define QVECTOR_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;
class Qvector {
public:
	struct Qpair {                                  /* Qvector�ڲ��� */
private:
		char	sym;                            /* ��Ʒ�ı�ʶ���磺'a','b','c','d','e','f'�� */
		double	w;                              /* ��Ʒ������ */
		double	v;                              /* ��Ʒ�ļ�ֵ */
		double	avg;                            /* avg=w/v */
		bool	sel;                            /* ��ʾ��Ʒ�Ƿ�װ�뱳��,0��ʾû��װ�룬1��ʾװ�� */
public:
		Qpair( char ch = '$', double tw = 1, double tv = 0 ) : sym( ch ), w( tw ), v( tv ), sel( false )
		{
			avg = v / w;
		}                                       /* ���캯�� */
		Qpair( const Qpair &rhs )               /* �������캯�� */
		{
			operator = (rhs);
		}
		Qpair & operator = (const Qpair &rhs)   /* ���������=����������Ϊ���ã������ԣ� */
		{
			if ( this != &rhs )             /* ��ֹ���Լ���ֵ */
			{
				sym	= rhs.sym;
				w	= rhs.w;
				v	= rhs.v;
				avg	= rhs.avg;
				sel	= rhs.sel;
			}
			return(*this);
		}
		double getW() const                                             /* ��ȡ��Ʒ������ */
		{
			return(w);
		}


		double getV() const                                             /* ��ȡ��Ʒ�ļ�ֵ */
		{
			return(v);
		}


		char getSym()                                                   /* ��ȡ��Ʒ�ı�ʶ�� */
		{
			return(sym);
		}


		double getAvg() const                                           /* ��ȡ��Ʒ�ĵ�λ��ֵ */
		{
			return(avg);
		}


		double getSel() const                                           /* ��ȡ��Ʒ�Ƿ�װ�뱳�� */
		{
			return(sel);
		}


		void setSym( char ch )                                          /* ������Ʒ�ı�ʶ�� */
		{
			sym = ch;
		}


		void setAvg( bool b )                                           /* ������Ʒ�ĵ�λ��ֵ */
		{
			sel = b;
		}


		void setW( double w )                                           /* ������Ʒ������ */
		{
			this->w = w;
		}


		void setV( double v )                                           /* ������Ʒ�ļ�ֵ */
		{
			this->v = v;
		}


		void setSel( bool b )                                           /* ������Ʒ�Ƿ�װ�뱳�� */
		{
			sel = b;
		}


		bool lessThan( const Qpair & rhs, int i )                       /* i������ʾ���Ǹ����ݳ�Ա���бȽ� */
		{
			if ( i == 3 )
				return(avg < rhs.avg);                          /* ̰�Ĳ��ԣ�ѡȡ��λ������ֵ������Ʒ */
			if ( i == 2 )
				return(v < rhs.v);                              /* ̰�Ĳ��ԣ�ѡȡ��ֵ����ߡ� */
			if ( i == 1 )
				return(w > rhs.w);                              /* ̰�Ĳ��ԣ���ѡȡ������С�� */
		}


		friend ostream & operator << (ostream & out, const Qpair &rhs)  /* ���������<< */
		{
			out << rhs.sym << "\t\t" << rhs.w << "\t\t" << rhs.v << "\t\t" << rhs.avg << "\t\t" << rhs.sel << endl;
			return(out);
		}
	};
private:
	int	theSize;
	int	theCapacity;
	Qpair	*objects;
public:
	Qvector( int i = 0 ) : theSize( 0 ), theCapacity( theSize + 15 )        /* ���캯�� */
	{
		objects = new Qpair[theCapacity];
	}
	~Qvector()                                                              /* �������� */
	{
		delete[] objects;
	}


	const Qvector & operator = (const Qvector &rhs)                         /* ���������=����������Ϊ���ã������ԣ� */
	{
		if ( this != &rhs )                                             /* �ж��Ƿ���Լ���ֵ */
		{
			delete[] objects;
			theSize		= rhs.theSize;
			theCapacity	= rhs.theCapacity;
			objects		= new Qpair[theCapacity];               /* ��Ϊ��仰�����˺ܶ����ע��ע�⣡ */
			for ( int k = 0; k < rhs.size(); ++k )
			{
				objects[k] = rhs.objects[k];
			}
		}
		return(*this);
	}
	Qvector( Qvector & rhs ) : objects( NULL )      /* �������캯�� */
	{
		operator = (rhs);
	}
	void reserve( int newCapacity )                 /* ��������theCapacity�Ĵ�С */
	{
		if ( newCapacity < theCapacity )
			return;
		Qpair *old = objects;
		theCapacity	= newCapacity;
		objects		= new Qpair[theCapacity];
		for ( int k = 0; k < theSize; ++k )
		{
			objects[k] = old[k];
		}
		delete[] old;
	}


	void resize( int newSize )
	{
		if ( newSize > theCapacity )
			reserve( newSize * 2 + 1 );
		theSize = newSize;
	}


	Qpair & operator[] (int index)                  /* ���������[] */
	{
		return(objects[index]);
	}
	const Qpair & operator[] (int index) const      /* ���������[] */
	{
		return(objects[index]);
	}
	int size() const
	{
		return(theSize);
	}


	int capacity() const
	{
		return(theCapacity);
	}


	void push_back( struct Qpair x )
	{
		if ( theSize == theCapacity )
		{
			reserve( theCapacity * 2 + 1 );
		}
		objects[theSize++] = x;
	}


	void sort( int s )                                              /* ������ѡȡ��̰�Ĳ��ԣ��������򣬲������� */
	{
		if ( 0 == s )                                           /* ʹ��ǰ��������̰�Ĳ��� */
		{
			for ( int k = 1; k <= 3; ++k )
			{
				select( k );                            /* ���� */
				outPut( k );                            /* ̰��ѡ�񣬲������� */
				initSel();                              /* �ָ�����ʼֵ */
			}
			select( 3 );                                    /* ������̰�Ĳ��ԣ���������ʽ̰���㷨 */
			Qvector temp = (*this);
			if ( this->size() > 2 )
				for ( int k1 = 0; k1 <= 2; ++k1 )       /* ����ʽ̰���㷨�У�k��Ԥ����ֵΪ2. */
				{
					Rec( temp, 1, k1 );
				}
			else                                            /* ���temp.size()==2��ֻ��ִ�д˹��̡� */
				Rec( temp, 1, 0 );
			outPut( 4 );
		}else  {
			if ( (s > 0) && (s < 4) )
			{
				select( s );
				outPut( s );
			}else  { /* ����ʽ̰���㷨 */
				select( 3 );                                    /*����ֵ�ܶȣ�����ֵ�����ȣ��������� */
				Qvector temp = (*this);
				if ( this->size() > 2 )
					for ( int k1 = 0; k1 <= 2; ++k1 )       /* ����ʽ̰���㷨�У�k��Ԥ����ֵΪ2. */
					{
						Rec( temp, 1, k1 );
					}
				else
					Rec( temp, 1, 0 );
				outPut( s );
			}
		}
	}


	void initSel() /* ��objects�ĸ���Qpair������лָ�����ʼֵ�� */
	{
		objects[0].setV( 0 );
		for ( int i = 1; i < size(); ++i )
		{
			if ( 1 == objects[i].getSel() )
			{
				objects[0].setW( objects[0].getW() + objects[i].getW() );
				objects[i].setSel( false );
			}
		}
	}


private:
	void select( int s ) /* �������ÿ����Ʒ���а�ĳ�ֲ��Խ�������ð������ */
	{
		for ( int i = 1; i < size() - 1; ++i )
		{
			int flag = 0;
			for ( int j = 1; j < size() - i; ++j )
			{
				if ( objects[j].lessThan( objects[j + 1], s ) )
				{
					Qpair temp = objects[j];
					objects[j]	= objects[j + 1];
					objects[j + 1]	= temp;
				}
				flag = 1;
			}
			if ( 0 == flag )
				return;
		}
	}


	void Greedy() /* ����̰��ѡ�� */
	{
		int q = 1;
		while ( (q < size() ) )
		{
			if ( (objects[q].getW() <= objects[0].getW() ) && objects[q].getV() != 0 )
			{
				objects[q].setSel( true );
				objects[0].setV( objects[0].getV() + objects[q].getV() );
				objects[0].setW( objects[0].getW() - objects[q].getW() );
			}
			++q;
		}
	}


	void outPut( int s )            /* �Խ����������� */
	{
		if ( 4 != s )
			Greedy();       /* ����̰��ѡ������ʽ̰�Ĳ��Բ�ʹ�ñ�Greedy()������ */
		if ( 4 == s )
			cout << "//̰�Ĳ���4������ʽ̰���㷨";
		if ( 3 == s )
			cout << "//̰�Ĳ���3��ѡȡ��λ������ֵ������Ʒ";
		if ( 2 == s )
			cout << "//̰�Ĳ���2��ѡȡ��ֵ�����";
		if ( 1 == s )
			cout << "//̰�Ĳ���1��ѡȡ������С";
		cout << "(isSelected��ʾ�Ƿ񽫸���Ʒװ�뱳��):" << endl;
		cout << "Symbol" << "\t\t" << "Weigh";
		if ( 1 == s )
			cout << "*";
		cout << "\t\tValue";
		if ( 2 == s )
			cout << "*";
		cout << "\t\tValue/Weight";
		if ( 3 == s )
			cout << "*";
		cout << "\tisSelected" << endl;
		cout << *this << endl;          /* ���������<< */
		cout << "װ�뱳����Ʒ������ܼ�ֵΪ: " << (*this)[0].getV() << endl << endl;
	}


	void Deal( Qvector & temp )             /* ����̰���㷨�Ĵ����� */
	{
		double	tw	= 0, tv = 0;
		int	initW	= 0, initV = 0;
		initW	= temp[0].getW();       /* ��������tempp[0]�ĳ�ʼֵ�� */
		initV	= temp[0].getV();
		for ( int i = 1; i < temp.size(); ++i )
		{
			if ( temp[i].getSel() )
			{
				tw	+= temp[i].getW();
				tv	+= temp[i].getV();
			}
		} /* ��tw>temp[0].getW()ʱ�������� */
		if ( tw <= temp[0].getW() ) /* ���S�Ӽ���Ʒ������С�ڱ������� */
		{
			temp[0].setW( temp[0].getW() - tw );
			temp[0].setV( temp[0].getV() + tv );
			if ( temp[0].getW() > 0 )
			{
				for ( int j = 1; j < temp.size(); ++j ) /* ����̰��ѡ�� */
				{
					if ( temp[j].getSel() )
						continue;
					if ( (temp[j].getW() <= temp[0].getW() ) && (temp[j].getV() > 0) ) /* ����Ʒj������С�ڵ�ǰ�������������Ҽ�ֵ����0ʱ�� */
					{
						temp[0].setW( temp[0].getW() - temp[j].getW() );
						temp[0].setV( temp[0].getV() + temp[j].getV() );
						temp[j].setSel( true );
					}
				}
			}
			if ( (*this)[0].getV() < temp[0].getV() )
			{
				(*this) = temp;
			}
			temp[0].setW( initW ); /* ��temp[0]���лָ� */
			temp[0].setV( initV );
		}


		/*for(int ss=1;ss<temp.size();++ss)
		 * cout<<temp[ss].getSel()<<' ';
		 * cout<<endl;*/
	}


	void Rec( Qvector & temp, int po, int rt )      /* ����ʽ̰���㷨�Ĵ�po��temp.size()-1��ѡȡrt��Qpair���� */
	{
		if ( 0 == rt )                          /* �ݹ�������� */
		{
			Deal( temp );
			return;
		}
		if ( (temp.size() - po) == rt )         /* �ݹ�������� */
		{
			for ( int i = po; i < temp.size(); ++i )
			{
				temp[i].setSel( true );
			}
			Deal( temp );
			return;
		}
		temp[po].setSel( true );
		Rec( temp, po + 1, rt - 1 );
		for ( int k2 = po + 1; k2 < temp.size(); ++k2 )         /* ע�� */
			temp[k2].setSel( false );

		temp[po].setSel( false );
		Rec( temp, po + 1, rt );
		for ( int k3 = po + 1; k3 < temp.size(); ++k3 )         /* ע�� */
			temp[k3].setSel( false );
	}


	friend ostream & operator << (ostream & out, Qvector & rhs)     /* ���������<< */
	{
		int n = 0;
		for ( int i = 1; i < rhs.size(); ++i )
		{
			out << rhs.objects[i];
			if ( rhs.objects[i].getSel() != 0 )
				++n;
		}
		cout << endl << "������ʣ������Ϊ: " << rhs.objects[0].getW() << endl
		<< "װ�뱳������Ʒ����Ϊ��" << n;
		return(out);
	}
};
#endif /* QVECTOR_H_INCLUDED */