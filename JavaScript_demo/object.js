'use strict';

/*��{...}��ʾһ�����󣬶��󱣴���Ǽ�ֵ��, �����Python��dict����, ��ͬ��֮һJavaScritp�еļ�ֵ�������ַ���, */
var Ljian = {
    name: 'ljian',
    age:  23,
    'high-school': 'QingYuan No.1 High School' //����Ч����Ҫ��''������
}

// ��������, object.prop��ʽ
Ljian.name;
Ljian.age;
Ljian[name];
Ljian['high-school'];    //����Ч������,Ҫ��[]��ʽ����

Ljian.age2;     //���ʲ��������ԣ��Ż�undefined

// ���ԵĶ�̬�����ɾ��
Ljian.age2 = '24';
delete Ljian.age2;

// �ж��Ƿ��������: prop in object
'age3' in Ljian;
'toString' in Ljian;    //��prop in object�жϣ� ���Դ��ڣ�����һ�����ǵ�ǰ���������ģ����������̳е�����

// �ж��Ƿ��Ƕ����Լ������Դ���: hasOwnProperty()����
Ljian.hasOwnProperty('name');
Ljian.hasOwnProperty('toString');







