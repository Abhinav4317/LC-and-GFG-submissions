/*
⚠️ Disclaimer -> ye post apke kuchh kimate samay lega.
Character -> Bhairava and Bujji (IYKYK)

Bhairava :- Bujji aaj ke LC contest ka 3rd problem dekha tumne.
Bujji :- Hn bhairava solve bhi kar diya maine.

Bhairava :- Flex karna jaruri hai kya ?
Bujji :- mai hu hi smart, flex karne ki need nhi mujhe.

Bhiarava :- mujhe question smjha do.
Bujji :- thik hai bas que samjahungi

Bhiarava :- kya bujji solution kaun samjhayega
Bujji :- to aise bolo n.

<!-- Explnation starts here -> thank you for your patience -->

Bujji :- dekh bhairava, tu 0 th index se start karega and tumjhe array
        ke end pe jana hai matlab ki n-1 index pe.

Bhairava :- thik hai thik hai, lekin ye to btavo, ki mai current ind
        se aage knha jana hai kaise choose kru ?
Bujji :- tum smart ho rhe ho bhairava, yhi to catch hai que me.
Bhairava :- bujji mai bachpan se hi smart hu.
Bujji :- Complex le chaloge to es question ki raj ki baat bataungi

Bhairava :- Bujji majak ka time nhi hai, raj ki baat bta do le chalunga jab bhi jaunga

Bujji :- dekho ham n cost maximum nikalanai hai.
Bhairava :- cost ab ye kya hai ??

Bujji :- dekho jab bhi tum i se j wali ind pe jaoge to uski cost 
        (j-i)*nums[i] hogi thik n.

Bhairava :-  hn hn yaad hai, yhi to puchch rha j kaise choose kru.

Bujji :- Dekho bhairava, tu hmesha apne next nearest maximum pe ruk
        jayega ?
Bhairava :- kya bujji mza nhi aaya, feel nhi huaa.
Bujji :- bhairava ek baar jake vo image dekh lo, copy me bna lo
        and meri baat ko match karna.

    Feel karte hai, solution ko:-

    Dekh bhairava, maine esiliye bola ki tu apne hamesha nearest max
    pe ruk jao, kyuki vhi tumhe maximum answer dega.

Bhairava :- kya bujji, tu to har line ke reason ke sath explain kari
        thi, feel nhi ho rha.

Bujji :- sabar rakh bhairava, feelk hoga mujhe complete kar de, ek
    flow me.

    Dekh bhairava, samjhate hai aakhir kyu, nearest maximum pe
    jane pe hi maximum answer milega ??

    [2,3,4]

    suppose main index 2 pe hu aur sidhe 4 pe ja rhi
    => 2*(2-0) => 4

    ab suppose mai, 3 ke sath hoke gyi
    => 2*1 + 3*1 => 5

    Dekh ye maximum kyu huaa, kyuki
    [2-----3-----4]
    Phele 2 ne socha mai sidhe 4 pe jaunga, to huaa kya ki, jo duri
    thi 3---4 ki ek index ki, usko bhi 2 hi cover krne laga to 
    value mili 1*2 => 2
    But agr vo duri 3 ke through jaye to value hogi 1*3 => 3 mili

    Matlab aise socho cost kya hai
    (j-i)*nums[i] -> mean ki aise combination ke kaise sare pair jo 
    hme n-1 tak le jaye 

    suppose main sidhe kyu nhi jata :-
    0 to n-1 index pe 
    (n-1)*nums[0] => ye answer tabhi maximum hoga jab current 0th max
    hoga, varna nhi hoga.

    Basically har difference kar liye, ham chahenge ki, har kadam pe
    jo maximum value ho skta hai nums[i] ki vo rakhe.


    aise samjhe 
    2   3   4 
    mai 0 se 2nd index pe ja rha bina ruke index 4 pe gya to 
    mai cost 4 hi bna paunga, jabki agr mai 3 pe rukta and then 4 pe
    jata to cost 5 bna pata, 

    Basic funda hai :- har kadam pe apna profict badhao,
        jab agla kadam rakho to, make sure karo ki, 
        jnha agla kadam rakhoge, uska se aage profit badhega hi.

I hope idea lga hoga, i think utna achhhe se nhi ho paya.

If u feel ki, uper se gya, drop a comment, i will definelty explain again.

Bhairava :- kuchch kuchh idea lga, ye btao aakhir ye implemet kaise 
    hoga, next nearest maximum wali chij.

Bujji :- Next greater elemenet yaad hai, uski help se, arey vo 
        stack wala, esiliye kehta hu, practice krte rho.

Bas to funda ye hai agle kadam pe maximum value honi chaiye.

Bhairava :- sochta hu ispe thoda.
*/

class Solution {
public:
    #define lli long long int
    
    lli solve(vector<int>& nums, vector<lli>& ngr, int ind, int n) {
        if (ind >= n - 1) return 0;

        // tum ese normal tarike se kar skte the.
        // loop se, ya phir aise bhi

        lli ans = 0;
        // agr aage koi maximum nhi to,
        // jnha hu vhi largest value hai, then esi se pura traver kar
        // du n-1 index tak.
        if (ngr[ind] == -1) {
            ans = (1LL * (n - ind - 1) * nums[ind]) + solve(nums, ngr, n - 1, n);
        } else {
            // aage koi maximum hai to
            // vnha tak chla jata hu
            ans = 1LL * (ngr[ind] - ind ) * nums[ind] + solve(nums, ngr, ngr[ind], n);
        }

        return ans;
    }
    
    long long findMaximumScore(vector<int>& nums) {
        lli n = nums.size();
        
        vector<lli> ngr(n, -1);

        stack<lli> st;
        // simple ngr.
        for (lli i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ngr[i] = st.top();
            }
            st.push(i);
        }

        // solve karne gye
        return solve(nums, ngr, 0, n);
    }
    // bye bye happy coding.
};