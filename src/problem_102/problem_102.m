function count = problem_102(filename)

if nargin < 1
   filename = 'triangles.txt';
end

triList = importdata(filename, ',');

count = 0;

for tri = 1:size(triList,1)
   a = triList(tri,1:2);
   b = triList(tri,3:4);
   c = triList(tri,5:6);

   plotTri(a,b,c, [0 0]);
   bndPoint = insideTri(a,b,c, [0 0]);
   showTri(a,b,c, [0 0], bndPoint)
   if bndPoint
      count = count + 1;
   end

end

fprintf('\n')
fprintf('Triangles containing the point [%d %d] = %d\n', [0 0], count);

%----------------------
function theta = getAngle(a,b)
x = b(1) - a(1);
y = b(2) - a(2);

theta = atan2(y,x);

%----------------------
function bndFlag = bndAngle(a,b,c,d)
bndFlag = false;

theta(1) = getAngle(a,b);
theta(2) = getAngle(a,c);
theta(3) = getAngle(a,d);

theta = unwrap(theta);

% Check if theta is monotonic (increasing OR decreasing)
if ( (theta(1)<theta(2)  &&  theta(2)<theta(3))  || ...
     (theta(1)>theta(2)  &&  theta(2)>theta(3)) )
  bndFlag = true;
end

%----------------------
function insideFlag = insideTri(a,b,c,test)

if ( false == bndAngle(a,b,test,c))
   insideFlag = false;
elseif ( false == bndAngle(b,a,test,c))
   insideFlag = false;
elseif ( false == bndAngle(c,a,test,b))
   insideFlag = false;
else
   insideFlag = true;
end

%----------------------
function showTri(a,b,c,d,insideFlag)

fprintf('Triangle A[%4d %4d], B[%4d %4d], C[%4d %4d]', a, b, c);
if false == insideFlag
   fprintf(' does not contain');
else
   fprintf(' contains');
end
fprintf(' the point [%d %d]\n', d);

%----------------------
function plotTri(a, b, c, test)
x = [a(1) b(1) c(1) a(1)];
y = [a(2) b(2) c(2) a(2)];

plot(x, y, ...
   'LineStyle',       '-', ...
   'Marker',          'o', ...
   'MarkerEdgeColor', 'r', ...
   'MarkerSize',      14);
hold on;
plot(test(1), test(2), ...
   'LineStyle',       '-', ...
   'Marker',          's', ...
   'MarkerEdgeColor', 'm', ...
   'MarkerFaceColor', 'c', ...
   'MarkerSize',      14);
hold off
grid on
axis equal
text(a(1), a(2), 'A');
text(b(1), b(2), 'B');
text(c(1), c(2), 'C');
title(sprintf('A[%4d %4d], B[%4d %4d], C[%4d %4d]', a, b, c))
drawnow