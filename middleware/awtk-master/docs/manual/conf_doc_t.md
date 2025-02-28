## conf\_doc\_t
### 概述
代表整个配置文件。
----------------------------------
### 函数
<p id="conf_doc_t_methods">

| 函数名称 | 说明 | 
| -------- | ------------ | 
| <a href="#conf_doc_t_conf_doc_append_child">conf\_doc\_append\_child</a> | 追加一个子节点。 |
| <a href="#conf_doc_t_conf_doc_append_sibling">conf\_doc\_append\_sibling</a> | 追加一个兄弟节点。 |
| <a href="#conf_doc_t_conf_doc_create">conf\_doc\_create</a> | 构造函数。 |
| <a href="#conf_doc_t_conf_doc_create_node">conf\_doc\_create\_node</a> | 创建一个空节点。 |
| <a href="#conf_doc_t_conf_doc_destroy">conf\_doc\_destroy</a> | 析构函数。 |
| <a href="#conf_doc_t_conf_doc_destroy_node">conf\_doc\_destroy\_node</a> | 销毁节点对象。 |
| <a href="#conf_doc_t_conf_doc_exists">conf\_doc\_exists</a> | 判断指定路径的节点是否存在。 |
| <a href="#conf_doc_t_conf_doc_get">conf\_doc\_get</a> | 获取指定路径节点的值。 |
| <a href="#conf_doc_t_conf_doc_remove">conf\_doc\_remove</a> | 删除指定路径的节点。 |
| <a href="#conf_doc_t_conf_doc_remove_child">conf\_doc\_remove\_child</a> | 删除指定的子节点。 |
| <a href="#conf_doc_t_conf_doc_remove_child_by_name">conf\_doc\_remove\_child\_by\_name</a> | 删除指定的子节点。 |
| <a href="#conf_doc_t_conf_doc_remove_children">conf\_doc\_remove\_children</a> | 删除全部子节点。 |
| <a href="#conf_doc_t_conf_doc_remove_sibling">conf\_doc\_remove\_sibling</a> | 删除指定的兄弟节点。 |
| <a href="#conf_doc_t_conf_doc_set">conf\_doc\_set</a> | 设置指定路径节点的值。 |
### 属性
<p id="conf_doc_t_properties">

| 属性名称 | 类型 | 说明 | 
| -------- | ----- | ------------ | 
| <a href="#conf_doc_t_root">root</a> | conf\_node\_t* | 根节点。 |
#### conf\_doc\_append\_child 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_append_child">追加一个子节点。

* 函数原型：

```
ret_t conf_doc_append_child (conf_doc_t* doc, conf_node_t* node, conf_node_t* child);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| node | conf\_node\_t* | 节点对象。 |
| child | conf\_node\_t* | 待追加节点对象。 |
#### conf\_doc\_append\_sibling 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_append_sibling">追加一个兄弟节点。

* 函数原型：

```
ret_t conf_doc_append_sibling (conf_doc_t* doc, conf_node_t* node, conf_node_t* sibling);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| node | conf\_node\_t* | 节点对象。 |
| sibling | conf\_node\_t* | 待追加节点对象。 |
#### conf\_doc\_create 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_create">构造函数。

* 函数原型：

```
conf_doc_t* conf_doc_create (uint32_t prealloc_nodes_nr);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | conf\_doc\_t* | 返回doc对象。 |
| prealloc\_nodes\_nr | uint32\_t | 预先分配的节点数。 |
#### conf\_doc\_create\_node 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_create_node">创建一个空节点。

* 函数原型：

```
conf_node_t* conf_doc_create_node (conf_doc_t* doc, const char* name);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | conf\_node\_t* | 返回节点对象。 |
| doc | conf\_doc\_t* | 文档对象。 |
| name | const char* | 节点名称。 |
#### conf\_doc\_destroy 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_destroy">析构函数。

* 函数原型：

```
ret_t conf_doc_destroy (conf_doc_t* doc);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
#### conf\_doc\_destroy\_node 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_destroy_node">销毁节点对象。

* 函数原型：

```
ret_t conf_doc_destroy_node (conf_doc_t* doc, conf_node_t* node);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| node | conf\_node\_t* | 节点对象。 |
#### conf\_doc\_exists 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_exists">判断指定路径的节点是否存在。

* 函数原型：

```
bool_t conf_doc_exists (conf_doc_t* doc, const char* path);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | bool\_t | 返回TRUE表示成功，FALSE表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| path | const char* | 节点的路径。 |
#### conf\_doc\_get 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_get">获取指定路径节点的值。

* 函数原型：

```
ret_t conf_doc_get (conf_doc_t* doc, const char* path, value_t* v);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| path | const char* | 节点的路径。 |
| v | value\_t* | 用于返回值。 |
#### conf\_doc\_remove 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_remove">删除指定路径的节点。

* 函数原型：

```
ret_t conf_doc_remove (conf_doc_t* doc, const char* path);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| path | const char* | 节点的路径。 |
#### conf\_doc\_remove\_child 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_remove_child">删除指定的子节点。

* 函数原型：

```
ret_t conf_doc_remove_child (conf_doc_t* doc, conf_node_t* node, conf_node_t* child);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| node | conf\_node\_t* | 节点对象。 |
| child | conf\_node\_t* | 待删除节点对象。 |
#### conf\_doc\_remove\_child\_by\_name 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_remove_child_by_name">删除指定的子节点。

* 函数原型：

```
ret_t conf_doc_remove_child_by_name (conf_doc_t* doc, conf_node_t* node, const char* name);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| node | conf\_node\_t* | 节点对象。 |
| name | const char* | 待删除节点的名称。 |
#### conf\_doc\_remove\_children 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_remove_children">删除全部子节点。

* 函数原型：

```
ret_t conf_doc_remove_children (conf_doc_t* doc, conf_node_t* node);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| node | conf\_node\_t* | 节点对象。 |
#### conf\_doc\_remove\_sibling 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_remove_sibling">删除指定的兄弟节点。

* 函数原型：

```
ret_t conf_doc_remove_sibling (conf_doc_t* doc, conf_node_t* node, conf_node_t* sibling);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| node | conf\_node\_t* | 节点对象。 |
| sibling | conf\_node\_t* | 待删除节点对象。 |
#### conf\_doc\_set 函数
-----------------------

* 函数功能：

> <p id="conf_doc_t_conf_doc_set">设置指定路径节点的值。

* 函数原型：

```
ret_t conf_doc_set (conf_doc_t* doc, const char* path, const value_t* v);
```

* 参数说明：

| 参数 | 类型 | 说明 |
| -------- | ----- | --------- |
| 返回值 | ret\_t | 返回RET\_OK表示成功，否则表示失败。 |
| doc | conf\_doc\_t* | 文档对象。 |
| path | const char* | 节点的路径。 |
| v | const value\_t* | 值。 |
#### root 属性
-----------------------
> <p id="conf_doc_t_root">根节点。

* 类型：conf\_node\_t*

