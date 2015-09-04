'use strict';

/*用{...}表示一个对象，对象保存的是键值对, 这个和Python的dict类似, 不同点之一JavaScritp中的键值必须是字符串, */
var Ljian = {
    name: 'ljian',
    age:  23,
    'high-school': 'QingYuan No.1 High School' //非有效变量要用''括起来
}

// 访问属性, object.prop形式
Ljian.name;
Ljian.age;
Ljian[name];
Ljian['high-school'];    //非有效变量名,要以[]形式访问

Ljian.age2;     //访问不存在属性，放回undefined

// 属性的动态添加与删除
Ljian.age2 = '24';
delete Ljian.age2;

// 判断是否存在属性: prop in object
'age3' in Ljian;
'toString' in Ljian;    //用prop in object判断， 属性存在，但不一定就是当前对象所属的，可能是它继承得来的

// 判断是否是对象自己的属性存在: hasOwnProperty()方法
Ljian.hasOwnProperty('name');
Ljian.hasOwnProperty('toString');







