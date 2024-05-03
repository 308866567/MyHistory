public boolean canPartitionKSubsets(int[] nums, int k) {
    // �ų�һЩ�������
    if (k > nums.length) return false;
    int sum = 0;
    for (int v : nums) sum += v;
    if (sum % k != 0) return false;
    int used = 0; // ʹ��λͼ����
    int target = sum / k;
    // k ��Ͱ��ʼʲô��ûװ���� nums[0] ��ʼ��ѡ��
    return backtrack(k, 0, nums, 0, used, target);
    }
    HashMap<Integer, Boolean> memo = new HashMap<>();
    boolean backtrack(int k, int bucket,
    int[] nums, int start, int used, int target) {
    // base case
    if (k == 0) {
    // ����Ͱ����װ���ˣ����� nums һ��ȫ��������
    return true;
    }
    if (bucket == target) {
    // װ���˵�ǰͰ���ݹ������һ��Ͱ��ѡ��
    // ����һ��Ͱ�� nums[0] ��ʼѡ����
    boolean res = backtrack(k - 1, 0, nums, 0, used, target);
    // ������
    memo.put(used, res);
    return res;
    }
    if (memo.containsKey(used)) {
    // �����������
    return memo.get(used);
    }
    for (int i = start; i < nums.length; i++) {
    // ��֦
    if (((used >> i) & 1) == 1) { // �жϵ� i λ�Ƿ��� 1
    // nums[i] �Ѿ���װ����Ͱ��
    continue;
    }
    if (nums[i] + bucket > target) {
    continue;
    }
    // ��ѡ��
    used |= 1 << i; // ���� i λ��Ϊ 1
    bucket += nums[i];
    // �ݹ������һ�������Ƿ�װ�뵱ǰͰ
    if (backtrack(k, bucket, nums, i + 1, used, target)) {
    return true;
    }
    // ����ѡ��
    used ^= 1 << i; // ʹ��������㽫�� i λ�ָ� 0
    bucket -= nums[i];
    }
    return false;
    }