/*
 *      ̰���㷨���0/1��������
 *      2012/06/12/
 */


/*
 * (1)̰�Ĳ��ԣ�ѡȡ������С."<<endl
 * (2)̰�Ĳ��ԣ�ѡȡ��ֵ�����."<<endl
 * (3)̰�Ĳ���: ѡȡ��λ������ֵ������Ʒ."<<endl
 * (4)̰�Ĳ��ԣ�����ʽ̰���㷨."<<endl;
 */
#include <iostream>
#include "Qvector.h"
using namespace std;
int main()
{
	cout << "/*̰���㷨���0/1��������*/" << endl << endl;
	Qvector vec;
	char	symbol; /* ��Ʒ�ı�ʾ�� */
	double	weight, value, Max = 0;
	cout << "�����뱳�����������磺50��" << endl;
	cin >> Max;     /* MaxΪ������������� */
	while ( Max <= 0 )
	{
		cout << "����������������롣" << endl;
		cin >> Max;
	}
	vec.push_back( Qvector::Qpair( '#', Max, 0 ) );
	/*
	 * vec[0].w��ʾ����ÿһ��̰��ѡ��󱳰���ʣ������
	 * vec[0].v���������ÿ��̰��ѡ�����ܼ�ֵ
	 */
	cout	<< "������ÿ����Ʒ�ı�ʶ���������Լ����ֵ�������(#,0,0)��ʾ���������" << endl
		<< "���磺��A 20 60������B 10 70������C 30 120������# 0 0��" << endl;
	cin >> symbol >> weight >> value;
	while ( symbol != '#' ) /* ��#��ʾ������� */
	{
		if ( (weight > 0) && (value >= 0) )
			vec.push_back( Qvector::Qpair( symbol, weight, value ) );
		else
			cout << "����������벻����������weight>0 and value>=0;���������룡" << endl;
		cin >> symbol >> weight >> value;
	}
	char con;
	do
	{
		int s;
		cout<< "��ѡ��̰�Ĳ���(0,1,2,3):" << endl
			<< "(0)ʹ������̰�Ĳ���" << endl
			<< "(1)̰�Ĳ��ԣ�ѡȡ������С." << endl
			<< "(2)̰�Ĳ��ԣ�ѡȡ��ֵ�����." << endl
			<< "(3)̰�Ĳ���: ѡȡ��λ������ֵ������Ʒ." << endl
			<< "*(4)̰�Ĳ��ԣ�����ʽ̰���㷨." << endl;
		cin >> s;
		while ( (s > 4) || (s < 0) )
		{
			cout << "����������������루0��1��2��3,4����" << endl;
			cin >> s;
		}
		cout << endl;
		vec.sort( s );
		/* �������ÿ����Ʒ����Value/Weight���Ĵ�С�������򣬲�����Ӧ���Խ���̰��ѡ������������� */
		vec.initSel(); /* ��vec�ָ�����ʼֵ�� */
		do
		{
			cout << "����ѡ��̰�Ĳ��ԣ�Y/N" << endl;
			cin >> con;
		}
		while ( !(con == 'y' || con == 'n' || con == 'Y' || con == 'y') );
	}
	while ( (con == 'y' || con == 'Y') );
	cout << "---������---" << endl;
	return(0);
}