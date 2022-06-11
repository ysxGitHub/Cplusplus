/*
给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
*/

double largestTriangleArea(vector<vector<int>>& points) {
    double ans = 0;
    for(int i=0; i<points.size(); ++i){
        for(int j=i+1; j<points.size(); ++j){
            for(int k=j+1; k<points.size(); ++k){
                double a = sqrt(pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2));
                double b = sqrt(pow(points[i][0]-points[k][0],2)+pow(points[i][1]-points[k][1],2));
                double c = sqrt(pow(points[k][0]-points[j][0],2)+pow(points[k][1]-points[j][1],2));
                double p = (a+b+c)*0.5;
                ans = max(ans, sqrt(p*(p-a)*(p-b)*(p-c)));
            }
        }
    }
    return ans;
}