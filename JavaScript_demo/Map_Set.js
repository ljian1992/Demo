'use strict';
/*Map数据类型，是ES6标准中，为了解决对象中键值只能为字符串而新出现的数据类型*/
var m = new Map([[1, '1'], [2, '2']]);

var m2 = new Map();
m2.set('gender',  'male')
m2.has('gender');
m2.get('gender')

/*Set数据类型： key的集合，重复的会被自动过滤*/
var s1 = new Set();
var s2 = new Set([1, 2, 3, 3, 3]);




