#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// json序列化示例1
void func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello";

    string sendBuf = js.dump(); // 将序列化后的json变成字符串格式

    cout << sendBuf.c_str() << endl;
}

// 序列化示例2
void func2()
{
    json js;
    // 添加数组
    js["id"] = {1, 2, 3, 4, 5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    // js["msg"]["zhang san"] = "hello world";
    // js["msg"]["liu shuo"] = "hello china";

    // 跟上面的效果一样
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};

    cout << js << endl;
}

// json序列化示例3
void func3()
{
    json js;

    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;

    cout << js << endl;
}

int main()
{
    // func1();
    // func2();
    func3();

    return 0;
}