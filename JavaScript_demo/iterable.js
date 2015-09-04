'use strict';
/*在ES6标准当中，引入了新的iterable类型，其中Array, Map, Set都属于iterable类型
* iteralbe对象迭代方式： 1.for of, 2.forEach()
* 而iterable类型都能被for of 迭代, for of 迭代就像Python 中的 for in, 它只迭代集合本身的元素
*
* 在数组中，每一个元素的索引被是为一个属性， for in 实际上迭代的是对象的属性，因此，for in 迭代数组，返回的是下标
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


/*迭代方式1：用 for of*/
//迭代数组
for (var x of a){
    alert(x);
}

//迭代Set
for (var x of s){
    alert(x)
}

//迭代Map
for(var x of m){
    alert(x[0]+':'+x[1])
}


/*迭代方式2：用iterable对象中内置的forEach方法*/
var a = ['a', 'b', 'c'];
var s = new Set(['a', 'b', 'c']);
var m = new Map([['a', 1], ['b', 2], ['c', 3]]);

a.forEach(function (element, index, array){
    // element: 指向当前元素值
    // index: 执行当前索引
    // array: 执行Array对象本身
    alert(element);

});

s.forEach(function(element, set){
    alert(element);
});

m.forEach(function(value, key, map){
    alert(value);
});

