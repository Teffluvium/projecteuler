function revNumCount = getRevNumCount2( maxNum )
% #define MAX 1000000000
%
% int main (int argc, char ** argv)
% {
%     int num = 0;
%     for (int i=0; i<MAX; ++i)
%         if (is_reversible (i))
%             ++num;
%     printf ("%d\n", num);
%     return 0;
% }
if nargin<1
    maxNum = 1e4;
end

revNumCount = 0;

for k = 1:maxNum
    if isReversible( k )
        revNumCount = revNumCount + 1;
    end
end


end

%%
function nDigits = numDigits( n )
% int len (int a)
% {
%     int n_digits = 0;
%     while (a > 0)
%     {
%         ++n_digits;
%         a /= 10;
%     }
%     return n_digits;
% }
nDigits = 0;
while n>0
    nDigits = nDigits + 1;
    n = floor( n / 10 );
end

end


%%
function status = allOdd( n )
%
% int all_odd (int a)
% {
%     int n_digits = len (a);
%     for (int i=0; i<n_digits; ++i)
%     {
%         if ( a%2 == 0 )
%             return 0;
%         a /= 10;
%     }
%     return 1;
% }
%
% nDigits = numDigits( n );
% for k = 1:nDigits
while n > 0
    if isequal( mod( n, 2 ), 0 )
        status = 0;
        return
    else
        n = floor( n / 10 );
    end
    status = 1;
end
end

%%
function status = isReversible( n )
% int is_reversible (int a)
% {
%     if (a % 10 == 0) // No leading zeros
%         return 0;
%     int n_digits = len (a);
%     int sum = 0;
%     for (int i=0; i<n_digits; ++i)
%     {
%         int val = a % 10;
%         sum += val*( (int) pow (10, i)) + val*( (int)pow (10, n_digits - i - 1));
%         a /= 10; // Next digit
%     }
%     if (all_odd (sum))
%         return 1;
%     return 0;
% }
%
status = 0;
if isequal( mod( n, 10 ), 0 )
    return
end
nDigits = numDigits( n );
revSum  = 0;
for k = 1:nDigits
    val    = mod( n, 10 );
    revSum = revSum + val*(10^(k-1))  +  val*10^(nDigits - k);
    n      = floor( n / 10 );
end
if allOdd( revSum )
    status = 1;
end
end