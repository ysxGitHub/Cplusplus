/*
给定一个表示代码片段的字符串，你需要实现一个验证器来解析这段代码，并返回它是否合法。合法的代码片段需要遵守以下的所有规则：

    1.代码必须被合法的闭合标签包围。否则，代码是无效的。
    2.闭合标签（不一定合法）要严格符合格式：<TAG_NAME>TAG_CONTENT</TAG_NAME>。其中，<TAG_NAME>是起始标签，</TAG_NAME>是结束标签。起始和结束标签中的 TAG_NAME 应当相同。3当且仅当 TAG_NAME 和 TAG_CONTENT 都是合法的，闭合标签才是合法的。
    4.合法的 TAG_NAME 仅含有大写字母，长度在范围 [1,9] 之间。否则，该 TAG_NAME 是不合法的。
    5.合法的 TAG_CONTENT 可以包含其他合法的闭合标签，cdata （请参考规则7）和任意字符（注意参考规则1）除了不匹配的<、不匹配的起始和结束标签、不匹配的或带有不合法 TAG_NAME 的闭合标签。否则，TAG_CONTENT 是不合法的。
    6.一个起始标签，如果没有具有相同 TAG_NAME 的结束标签与之匹配，是不合法的。反之亦然。不过，你也需要考虑标签嵌套的问题。
    7.一个<，如果你找不到一个后续的>与之匹配，是不合法的。并且当你找到一个<或</时，所有直到下一个>的前的字符，都应当被解析为 TAG_NAME（不一定合法）。
    cdata 有如下格式：<![CDATA[CDATA_CONTENT]]>。CDATA_CONTENT 的范围被定义成 <![CDATA[ 和后续的第一个 ]]>之间的字符。
    8.CDATA_CONTENT 可以包含任意字符。cdata 的功能是阻止验证器解析CDATA_CONTENT，所以即使其中有一些字符可以被解析为标签（无论合法还是不合法），也应该将它们视为常规字符。

*/
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string code) {
    stack<string> st;
    for(int i = 0; i < code.size(); i++) {
        /* 分类1: 出现 "" */
        if(i > 0 && st.empty()) return false;
        /* 分类2: 出现"<![CDATA[" */
        if(code.substr(i, 9) == "<![CDATA[") {
            int j = i + 9;
            i = code.find("]]>", j);// 找到"]]>"
            if (i < 0) return false;
            i += 2;
        }  /* 分类3: 出现"</" */
        else if(code.substr(i, 2) == "</") {
            int j = i + 2;
            i = code.find(">", j);  //找到">"
            if (i < 0) return false;
            /* 截取标签内容 */
            string tag = code.substr(j, i - j);
            /* 与之前存入的标签前段相比，是否匹配 */
            if (st.empty() || st.top() != tag) return false;
            st.pop();
        }  /* 分类4: 出现"<" */
        else if(code.substr(i, 1) == "<") {
            int j = i + 1;
            i = code.find(">", j);               //找到">"
            /* 如果标签长度超过9就错误 */
            if (i < 0 || i == j || i - j > 9) return false;
            /* 标签字母要求大写 */
            for (int k = j; k < i; k++)
                if (code[k] < 'A' || code[k] > 'Z') return false;
            /* 将标签内容存入栈中 */
            string tag = code.substr(j, i - j);
            st.push(tag);
        }
    }
    return st.empty();
}

int main(int argc, char const *argv[])
{
    string s="sahdg";
    cout<<s.find("ahd")<<endl;
    return 0;
}
