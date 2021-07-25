class Solution {
    public String removeOuterParentheses(String s) {
        Stack <Character> st=new Stack<Character>();
        String result="";
        int c=0;
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            if(ch=='(')
            {
                c++;
                st.push(ch);
            }
            else
            {
                c--;
                st.push(ch);
            }
            if(c==0)
            {
                st.pop();
                String res="";
                while(st.size()!=1)
                {
                    res=st.pop()+res;
                }
                st.clear();
                result=result+res;
            }
            
        }
        return result;
    }
}