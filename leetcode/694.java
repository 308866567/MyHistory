int numDistinctIslands(int[][] grid) {
    int m = grid.length, n = grid[0].length;
    // ��¼���е�������л����
    HashSet<String> islands = new HashSet<>();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
            // �͵�������죬ͬʱ�洢��������л����
            StringBuilder sb = new StringBuilder();
            // ��ʼ�ķ���������д����Ӱ����ȷ��
            dfs(grid, i, j, sb, 666);
            islands.add(sb.toString());    
            }
        }
    }
    // ����ͬ�ĵ�������
    return islands.size();
    }
void dfs(int[][] grid, int i, int j, StringBuilder sb, int dir) {
    int m = grid.length, n = grid[0].length;
    if (i < 0 || j < 0 || i >= m || j >= n|| grid[i][j] == 0) {
        return;
        }
    // ǰ�����λ�ã����� (i, j)
    grid[i][j] = 0;
    sb.append(dir).append(',');
    dfs(grid, i - 1, j, sb, 1); // ��
    dfs(grid, i + 1, j, sb, 2); // ��
    dfs(grid, i, j - 1, sb, 3); // ��
    dfs(grid, i, j + 1, sb, 4); // ��
    // �������λ�ã��뿪 (i, j)
    sb.append(-dir).append(',');
}