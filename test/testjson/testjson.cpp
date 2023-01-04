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

    js["id"] = {1, 2, 3, 4, 5};
    js["name"] = "zhang san";
    // 添加对象
    // js["msg"]["zhang san"] = "hello world";
    // js["msg"]["liu shuo"] = "hello china";

    // 跟上面的效果一样
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};

    cout << js << endl;
}

int main()
{
    // func1();
    func2();
    return 0;
}