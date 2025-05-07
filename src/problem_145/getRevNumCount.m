function revNumCount = getRevNumCount( maxNum )

% How many reversible numbers are there below one-billion?
% Problem 145
%
% Some positive integers n have the property that the sum [ n + reverse(n) ]
% consists entirely of odd (decimal) digits. For instance, 36 + 63 = 99 and 409
% + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904
% are reversible. Leading zeroes are not allowed in either n or reverse(n).
%
% There are 120 reversible numbers below one-thousand.
%
% How many reversible numbers are there below one-billion (10^9)?

% The solution is 608720

if nargin<1
    maxNum = 1000;
end

revNumCount = 0;

for n = 1:maxNum
    numVec    = vectorizeNum( n );
    
    % Skip any number with a leading or trailing zero
    if isequal( numVec(1), 0 )  ||  isequal( numVec(end), 0 );
        continue;
    end
    
    if numVec(1) < numVec(end)
        continue
    end
    
    [sumVec, status] = sumNumVec( numVec );
    
    if isequal( status, 0 )
        continue;
    end
    
    nTmp = dot( numVec, 10.^( (length(numVec)-1):-1:0) );
    
    if status
        if nTmp <= maxNum
            revNumCount = revNumCount + 2;
        else
            revNumCount = revNumCount + 1;
        end
    end
    
end

end

%%
function numVec = vectorizeNum( n )

nPowDigits = floor( log10( n ) );
numVec     = zeros( 1, nPowDigits+1 );

nTmp = n;
k    = 1;
while nTmp > 0
    numVec(k) = mod( nTmp, 10 );
    nTmp      = floor( nTmp / 10 );
    k         = k + 1;
end

end


%%
function [sumVec, status] = sumNumVec( a )

status = 0;
sumVec = zeros( size( a ) );

numDigits = length( a );
carry     = 0;

for k = 1:numDigits
    tmp = a(k) + a(end-k+1) + carry;
    
    if tmp >= 10
        carry     = floor( mod( tmp/10, 10 ) );
        sumVec(k) = mod( tmp, 10 );
    else
        carry     = 0;
        sumVec(k) = tmp;
    end
    
    % Check if each summed digit is odd
    if isequal( mod( sumVec(k), 2 ), 1 )
        status = 1;
    else
        status = 0;
        return
    end
end

if carry>0;
    sumVec(numDigits+1) = carry;
end

% Check if each summed digit is odd
if isequal( mod( sumVec(end), 2 ), 1 )
    status = 1;
else
    status = 0;
    return
end

end
