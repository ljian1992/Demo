'use strict';

var x = 0;
var i;
for (i = 1; i <= 100; ++i){
    x += i;
}
alert(x)

var Ljian = {
    name: 'ljian',
    age:  23,
    'high-school': 'QingYuan No.1 High School'
}


for (var key in Ljian){
    if(Ljian.hasOwnProperty(key)){
        alert(key);
    }
}

var arr = ['a', 'b', 'c'];
for (var index in arr){
    alert(arr[index]);      // 迭代得到的是下标, 不像Python是得到值
}

var x = 10;
while(x > 0){
}
x + 1;

var x = 10;
do{
    x + 1;
}while(x > 10);

