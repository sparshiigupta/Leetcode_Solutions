class Solution {
    public boolean isValid(String s) {
        Stack <Character> st=new Stack<Character>();
        int flag=0;
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            if(ch=='('||ch=='{'||ch=='[')
            {
                st.push(ch);
            }
            else
            {
                if(st.isEmpty()==true)
                {
                    flag=1;
                    break;
                }
                char c=st.peek();
                if(ch==')' && c=='(' || ch==']' && c=='[' || ch=='}' && c=='{')
                    st.pop();
                else
                {
                    
                }
            }
        }
        if(st.isEmpty()==true && flag==0)
            return true;
        else
            return false;
    }
}