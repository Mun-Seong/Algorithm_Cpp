// SWEA
// 1974 스도쿠 검증
#include <iostream>

using namespace std;

int	n;
int	board[9][9];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		// input
		bool	ans(true);
		for (int i=0;i<9;++i)
			for (int j=0;j<9;++j)
				cin >> board[i][j];

		// solution
		bool	out(false);
		int		tmp;
		for (int i=0;i<9;++i) {
			if (!ans)	break;
			int	nums[9]={0,};
			for (int j=0;j<9;++j) {
				if (nums[board[i][j]-1] > 0) {
					ans = false;
					break ;
				}
				nums[board[i][j]-1] += 1;
			}
		}
		if (!ans) {
			cout << '#' << test_case << ' ' << ans << '\n';
			continue;
		}
		for (int j=0;j<9;++j) {
			if (!ans)	break;
			int	nums[9]={0,};
			for (int i=0;i<9;++i) {
				if (nums[board[i][j]-1] > 0) {
					ans = false;
					break ;
				}
				nums[board[i][j]-1] += 1;
			}
		}
		if (!ans) {
			cout << '#' << test_case << ' ' << ans << '\n';
			continue;
		}
		for(int i = 0; i < 3; i++) {
            if(!ans) break; // 앞에서 한번이라도 불만족시 break
            for(int j = 0; j < 3; j++) {
                int check[9]={0,};
                for(int k = 0; k < 3; k++) {
                    for(int s = 0; s < 3; s++) {
                        if(check[board[3*i + k][3*j + s]-1]>0){
                            ans=false;
                            break;
                        }
                        check[board[3*i + k][3*j + s]-1]+=1;
                    }
                }
            }
        }


		// output
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}