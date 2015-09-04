/*
问题：1.NaN和自己比较都会不相等，怎么实现的
     2.在strict模式下，怎么声明全局变量
*/
'use strict';


/************************Number***************************/
123;
0.345;
NaN;            // Not a Number, 无法计算结果用NaN表示,与任何类型都不相等，包括和自己比较
Infinity;      // 无限大，当数值超过JavaScript的Number所能标识的最大值时,就是Infinity

/************************字符串***************************/
'Ljian';
"ljian";

/************************布尔值***************************/
true;
false;

/*空值*/
null;           //  ''是指长度为0的字符串，并非null
undefined;      // 是否定义

/************************逻辑运算符***************************/
true && false;
false || true;
!true;
!false;

/************************比较运算符***************************/
7 > 5;
7 >= 5;

false == 0;         // ==  比较，会进行自动类型转换，不要用它
false === 0;        // === 不会进行自动类型转换，数据类型不对，则返回false

NaN === NaN;

isNaN(NaN);

Math.abs(1/3 - 1/3) < 0.0000001;




/*数组，  JavaScript中的数组可以包括任意的数据类型*/
//创建数组方式
var arr = [1, 3, 'Ljian', false];
var arr2 = new Array[1, 3, 'Ljian', false];     //这个看着比较恶心，一般不用

arr[0];

/*对象*/
var person = {
    name: 'ljian',
    age: 23
}

person.name;
person.age;

/* 变量
*  变量不用var声明，则会自动被声明为全局变量, 会造成多文件中同名的全局变量冲突
*  strict模式：解决上面的问题，使到声明变量一定要用var声明
*       使用方式，在JavaScript代码的第一行写上: 'use strict'
*
* */
var a;          //声明变量
var b = 10;
b = 'ljian';


/*字符串
* 字符串是不可变的，对字符串操作，后放回的，是新的对象
* */
var hello = 'Hello world';
hello[13];      //超出范围，返回undefined

hello[0] = 'h'      // 字符串是不可变的，所以赋值也没用

//转换成大写
hello.toUpperCase()     //返回新创建的字符串, 'HELLO WORLD'

//转换成小写
hello.toLowerCase()

//搜索字符串出现的位置
hello.indexOf('world')

//返回子串
hello.substring(0, 5);  // 闭开区间[)


/*数组操作*/
//获取长度, 及改变长度
var array = [1, 3, 4, 5]

array.length = 20;      // length可以改变，小于原来的长度，则截取，大于原来的长度则不undefined

array[6] = 1;           // 数组大小会动态改变，在[6]中添加1,中间补undefined

//获取元素的位置
var array = [1, 3, 4, 5]
array.indexOf(5);           //获取元素5的索引，
array.indexOf(0);           //没找到放回-1

//返回子数组
var arr = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
arr.slice(1, 5);     // [1, 5)
arr.slice(5);        // [5, length)
arr.slice();        //  [0, length)  可以通过这个赋值数组

// push() -- 在Array末尾添加元素，返回新的Array的长度
// pop()  -- 删除Array的最后一个元素，返回被删除的，没有元素可以删除时，返回undefined
// 利用这两个方法，可以形成栈
var arr = ['a', 'b', 'c', 'd', 'e', 'f', 'g'];
arr.push('h', 'i');
arr.pop();

// unshift() -- 在Array头部添加元素，返回新的Array的长度
// shitf()   -- 删除Array的第一一个元素，返回被删除的元素，没有元素可以删除时，返回undefined
var arr = [1, 2, 3];
arr.unshift(0);
arr.shift();

// 排序, 默认，转换成str在进行排序
var arr = ['c', 'a', 'd'];
arr.sort();

// 反转
var arr = ['c', 'a', 'd'];
arr.reverse();

// splice方法: 可删除，可添加
var arr = ['Microsoft', 'Apple', 'Yahoo', 'AOL', 'Excite', 'Oracle'];
// 从索引2开始删除3个元素,然后再添加两个元素:
arr.splice(2, 3, 'Google', 'Facebook'); // 返回删除的元素 ['Yahoo', 'AOL', 'Excite']
arr; // ['Microsoft', 'Apple', 'Google', 'Facebook', 'Oracle']
// 只删除,不添加:
arr.splice(2, 2); // ['Google', 'Facebook']
arr; // ['Microsoft', 'Apple', 'Oracle']
// 只添加,不删除:
arr.splice(2, 0, 'Google', 'Facebook'); // 返回[],因为没有删除任何元素
arr; // ['Microsoft', 'Apple', 'Google', 'Facebook', 'Oracle']

// concat方法：数组拼接
var arr = ['a', 'b'];
var concat_arr = arr.concat(['c', 'd']);

// 把Array中的元素用指定字符/字符串连起来, 不是字符，会转换为字符串后再连接起来
var arr = ['a', 'a', 'c', 1, 2, 3]
arr.join('-');


