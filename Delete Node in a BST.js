var deleteNode = function(root, key) {
    if (root === null) {
        return null;
    }

    if (key < root.val) {
        root.left = deleteNode(root.left, key);
    } else if (key > root.val) {
        root.right = deleteNode(root.right, key);
    } else {
        if (root.left === null) {
            return root.right;
        } else if (root.right === null) {
            return root.left;
        }

        root.val = findSmallestInRightSubtree(root.right);
        root.right = deleteNode(root.right, root.val);
    }

    return root;
};

var findSmallestInRightSubtree = function(node) {
    while (node.left !== null) {
        node = node.left;
    }
    return node.val;
};
