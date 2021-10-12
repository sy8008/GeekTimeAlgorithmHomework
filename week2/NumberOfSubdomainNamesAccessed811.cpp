#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for (string str:cpdomains){

            // 将字符串中的域名分割出来
            int pos = str.find_first_of(" "); 
            int num = stoi(str.substr(0, pos + 1)); // 将数字分割出来
            string domain = str.substr(pos+1); // 将域名分割出来
            vector<string> splitedDomain = splitDomainStr(domain); //将域名分割
            
            for (string s:splitedDomain){ //为分割好的域名建hash表

                if (domain_map.find(s) == domain_map.end()) { // 若key不存在，则先插入
                    domain_map[s] = num;
                }
                else{ //否则累加
                    domain_map[s] += num;
                }
            }


        }

        vector<string> ans;
        //将结果组装成题目要求形式返回
        for (const pair<string,int> &p : domain_map){
            string temp = to_string(p.second) + " " + p.first;
            ans.push_back(temp);

        }
        return ans;
    }
private:

    // 将一个域名分割成其所有可能的域名组合
    vector<string>splitDomainStr(string domain){
        
        vector<string> splitedDomains;
        splitedDomains.push_back(domain);

        for (int i = 1; i < domain.size(); ++i){
            if (domain[i] == '.'){
                string sub_str = domain.substr(i+1);
                splitedDomains.push_back(sub_str);
            }
        }

        return splitedDomains;
    }

    unordered_map<string,int> domain_map;

};
int main(){
    Solution my_solution;
    unordered_map<string, int> m;
    m["test"] += 1;
    
    vector<string> input={"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> result = my_solution.subdomainVisits(input);
    for ( string s: result){
        cout << s << endl;
    }


    return 0;
}