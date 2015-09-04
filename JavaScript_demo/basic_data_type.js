/*
���⣺1.NaN���Լ��Ƚ϶��᲻��ȣ���ôʵ�ֵ�
     2.��strictģʽ�£���ô����ȫ�ֱ���
*/
'use strict';


/************************Number***************************/
123;
0.345;
NaN;            // Not a Number, �޷���������NaN��ʾ,���κ����Ͷ�����ȣ��������Լ��Ƚ�
Infinity;      // ���޴󣬵���ֵ����JavaScript��Number���ܱ�ʶ�����ֵʱ,����Infinity

/************************�ַ���***************************/
'Ljian';
"ljian";

/************************����ֵ***************************/
true;
false;

/*��ֵ*/
null;           //  ''��ָ����Ϊ0���ַ���������null
undefined;      // �Ƿ���

/************************�߼������***************************/
true && false;
false || true;
!true;
!false;

/************************�Ƚ������***************************/
7 > 5;
7 >= 5;

false == 0;         // ==  �Ƚϣ�������Զ�����ת������Ҫ����
false === 0;        // === ��������Զ�����ת�����������Ͳ��ԣ��򷵻�false

NaN === NaN;

isNaN(NaN);

Math.abs(1/3 - 1/3) < 0.0000001;




/*���飬  JavaScript�е�������԰����������������*/
//�������鷽ʽ
var arr = [1, 3, 'Ljian', false];
var arr2 = new Array[1, 3, 'Ljian', false];     //������űȽ϶��ģ�һ�㲻��

arr[0];

/*����*/
var person = {
    name: 'ljian',
    age: 23
}

person.name;
person.age;

/* ����
*  ��������var����������Զ�������Ϊȫ�ֱ���, ����ɶ��ļ���ͬ����ȫ�ֱ�����ͻ
*  strictģʽ�������������⣬ʹ����������һ��Ҫ��var����
*       ʹ�÷�ʽ����JavaScript����ĵ�һ��д��: 'use strict'
*
* */
var a;          //��������
var b = 10;
b = 'ljian';


/*�ַ���
* �ַ����ǲ��ɱ�ģ����ַ�����������Żصģ����µĶ���
* */
var hello = 'Hello world';
hello[13];      //������Χ������undefined

hello[0] = 'h'      // �ַ����ǲ��ɱ�ģ����Ը�ֵҲû��

//ת���ɴ�д
hello.toUpperCase()     //�����´������ַ���, 'HELLO WORLD'

//ת����Сд
hello.toLowerCase()

//�����ַ������ֵ�λ��
hello.indexOf('world')

//�����Ӵ�
hello.substring(0, 5);  // �տ�����[)


/*�������*/
//��ȡ����, ���ı䳤��
var array = [1, 3, 4, 5]

array.length = 20;      // length���Ըı䣬С��ԭ���ĳ��ȣ����ȡ������ԭ���ĳ�����undefined

array[6] = 1;           // �����С�ᶯ̬�ı䣬��[6]�����1,�м䲹undefined

//��ȡԪ�ص�λ��
var array = [1, 3, 4, 5]
array.indexOf(5);           //��ȡԪ��5��������
array.indexOf(0);           //û�ҵ��Ż�-1

//����������
var arr = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
arr.slice(1, 5);     // [1, 5)
arr.slice(5);        // [5, length)
arr.slice();        //  [0, length)  ����ͨ�������ֵ����

// push() -- ��Arrayĩβ���Ԫ�أ������µ�Array�ĳ���
// pop()  -- ɾ��Array�����һ��Ԫ�أ����ر�ɾ���ģ�û��Ԫ�ؿ���ɾ��ʱ������undefined
// ���������������������γ�ջ
var arr = ['a', 'b', 'c', 'd', 'e', 'f', 'g'];
arr.push('h', 'i');
arr.pop();

// unshift() -- ��Arrayͷ�����Ԫ�أ������µ�Array�ĳ���
// shitf()   -- ɾ��Array�ĵ�һһ��Ԫ�أ����ر�ɾ����Ԫ�أ�û��Ԫ�ؿ���ɾ��ʱ������undefined
var arr = [1, 2, 3];
arr.unshift(0);
arr.shift();

// ����, Ĭ�ϣ�ת����str�ڽ�������
var arr = ['c', 'a', 'd'];
arr.sort();

// ��ת
var arr = ['c', 'a', 'd'];
arr.reverse();

// splice����: ��ɾ���������
var arr = ['Microsoft', 'Apple', 'Yahoo', 'AOL', 'Excite', 'Oracle'];
// ������2��ʼɾ��3��Ԫ��,Ȼ�����������Ԫ��:
arr.splice(2, 3, 'Google', 'Facebook'); // ����ɾ����Ԫ�� ['Yahoo', 'AOL', 'Excite']
arr; // ['Microsoft', 'Apple', 'Google', 'Facebook', 'Oracle']
// ֻɾ��,�����:
arr.splice(2, 2); // ['Google', 'Facebook']
arr; // ['Microsoft', 'Apple', 'Oracle']
// ֻ���,��ɾ��:
arr.splice(2, 0, 'Google', 'Facebook'); // ����[],��Ϊû��ɾ���κ�Ԫ��
arr; // ['Microsoft', 'Apple', 'Google', 'Facebook', 'Oracle']

// concat����������ƴ��
var arr = ['a', 'b'];
var concat_arr = arr.concat(['c', 'd']);

// ��Array�е�Ԫ����ָ���ַ�/�ַ���������, �����ַ�����ת��Ϊ�ַ���������������
var arr = ['a', 'a', 'c', 1, 2, 3]
arr.join('-');


