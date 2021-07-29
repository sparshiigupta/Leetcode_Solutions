class Solution {
    public int[] solve(int[] num2)
    {
        int next[]=new int[num2.length];
        Stack <Integer> st=new Stack<Integer>();
        for(int i=num2.length-1;i>=0;i--)
        {
            if(st.isEmpty())
                next[i]=-1;
            else
            {
                if(st.peek()>num2[i])
                {
                    next[i]=st.peek();
                }
                else
                {
                    while(st.size()>0 && st.peek()<=num2[i])
                    {
                        st.pop();
                    }
                    if(st.isEmpty())
                        next[i]=-1;
                    else
                    {
                        next[i]=st.peek();
                    }
                }
            }
            st.push(num2[i]);
        }
        return next;
    }
    public int[] nextGreaterElement(int[] num1, int[] num2) {
        int next[]=solve(num2);
        HashMap<Integer,Integer> mp= new HashMap<Integer,Integer>();
        for(int i=0;i<num2.length;i++)
        {
            mp.put(num2[i],next[i]);
        }
        int ans[]=new int[num1.length];
        for(int i=0;i<num1.length;i++)
        {
            if(mp.containsKey(num1[i]))
               ans[i]=mp.get(num1[i]);
        }
               return ans;
    }
}