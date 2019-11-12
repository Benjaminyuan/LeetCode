public class WildCardMatching {
    public boolean isMatch(String s,String p){
        boolean[][] match = new boolean[s.length()+1][p.length()+1];
        match[s.length()][p.length()] = true;
        for(int i = p.length()-1;i>=0;i--){
            if (p.charAt(i)!='*'){
                break;
            }else{
                match[s.length()][i] = true;
            }
        }
        for(int i = s.length()-1;i>=0;i--){
            for(int j = p.length()-1;j>=0;j--){
                if(s.charAt(i)==p.charAt(j)||p.charAt(j)=='?'){
                    match[i][j] = match[i+1][j+1];
                }else if(p.charAt(j)=='*'){
                    match[i][j] = match[i][j+1]||match[i+1][j];
                }else{
                    match[i][j] = false;
                }
            }
        }
        return match[0][0];
    }
//    public boolean isMatch_2(String s,String p){
//        int star = -1;
//        int s_pos = 0;
//        int s_temp = 0;
//        int p_pos = 0;
//        while(s_pos<s.length()){
//            if(s.charAt(s_pos)==p.charAt(p_pos)||p.charAt(p_pos)=='?'){
//                s_pos++;
//                p_pos++;
//            }else if(p.charAt(p_pos)=='*'){
//                star = p_pos++;
//                s_temp = s_pos;
//            }else if(star>=0){
//                p_pos = star+1;
//                s_pos = ++s_temp;
//            }else{
//                return false;
//            }
//        }
//        while(p_pos<=p.length()-1){
//            if(p.charAt(p_pos)=='*'){
//                p_pos++;
//            }
//        }
//        return p_pos>=p.length();
//    }

    public static void main(String[] arg){
        WildCardMatching wildCardMatching = new WildCardMatching();
        System.out.println(wildCardMatching.isMatch("ho", "ho**"));
        System.out.println(wildCardMatching.isMatch("ho", "ho**"));

    }
}
