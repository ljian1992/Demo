'use strict';
/*��ES6��׼���У��������µ�iterable���ͣ�����Array, Map, Set������iterable����
* iteralbe���������ʽ�� 1.for of, 2.forEach()
* ��iterable���Ͷ��ܱ�for of ����, for of ��������Python �е� for in, ��ֻ�������ϱ����Ԫ��
*
* �������У�ÿһ��Ԫ�ص���������Ϊһ�����ԣ� for in ʵ���ϵ������Ƕ�������ԣ���ˣ�for in �������飬���ص����±�
* var a = ['a', 'b', 'c'];
* a.name = 'Ljian';
* for (var x in a){
*   alert(x);       // '0', '1', '2', 'name'
* }
*
* */

var a = ['a', 'b', 'c'];
var s = new Set(['a', 'b', 'c']);
var m = new Map([['a', 1], ['b', 2], ['c', 3]]);


/*������ʽ1���� for of*/
//��������
for (var x of a){
    alert(x);
}

//����Set
for (var x of s){
    alert(x)
}

//����Map
for(var x of m){
    alert(x[0]+':'+x[1])
}


/*������ʽ2����iterable���������õ�forEach����*/
var a = ['a', 'b', 'c'];
var s = new Set(['a', 'b', 'c']);
var m = new Map([['a', 1], ['b', 2], ['c', 3]]);

a.forEach(function (element, index, array){
    // element: ָ��ǰԪ��ֵ
    // index: ִ�е�ǰ����
    // array: ִ��Array������
    alert(element);

});

s.forEach(function(element, set){
    alert(element);
});

m.forEach(function(value, key, map){
    alert(value);
});

