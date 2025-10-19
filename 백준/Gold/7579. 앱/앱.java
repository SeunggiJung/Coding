import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    
    // C++의 pair<int, int> ac;를 두 개의 배열로 대체합니다.
    static int[] memory; // ac[i].first
    static int[] cost;   // ac[i].second
    static int[] dp;
    static int N, M;
    static final int INF = 99999999;

    public static void main(String[] args) throws IOException {
        
        // C++의 fast I/O (ios::sync_with_stdio(false); cin.tie(nullptr);)에 해당
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // cin >> N >> M;
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // ac.assign(N, {});
        memory = new int[N];
        cost = new int[N];
        
        // dp.assign(M + 1, INF);
        dp = new int[M + 1];
        Arrays.fill(dp, INF);
        
        // dp[0]=0;
        dp[0] = 0;
        
        // int ans=INF;
        int ans = INF;

        // C++의 첫 번째 입력 루프 (ac[i].first)
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            memory[i] = Integer.parseInt(st.nextToken());
        }

        // C++의 두 번째 입력 루프 (ac[i].second) 및 DP 로직
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            cost[i] = Integer.parseInt(st.nextToken());
            
            // for(int j=M-1; j>=0; j--)
            for (int j = M - 1; j >= 0; j--) {
                // if(dp[j]==INF) continue;
                if (dp[j] == INF) continue;

                // C++의 로직을 if-else로 변환 (continue를 사용한 구조)
                // if(ac[i].first+j>=M)
                if (memory[i] + j >= M) {
                    // ans = min(ans, dp[j] + ac[i].second);
                    ans = Math.min(ans, dp[j] + cost[i]);
                    // C++ 코드는 여기서 continue; 됩니다.
                } else {
                    // dp[ac[i].first+j] = min(dp[ac[i].first+j], dp[j] + ac[i].second);
                    dp[memory[i] + j] = Math.min(dp[memory[i] + j], dp[j] + cost[i]);
                }
            }
        }

        // cout << ans;
        bw.write(ans + "\n");
        
        // 스트림 정리
        bw.flush();
        bw.close();
        br.close();
    }
}