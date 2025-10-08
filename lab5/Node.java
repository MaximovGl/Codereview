package ru.maximov.tree;
/*
Необходимо реализовать структуру данных, представляющую собой простейшее бинарное
дерево. Для формирования данного дерева будет использоваться сущность Узел.
Состояние сущности описывается следующими характеристиками:
o Значение, целое число
o Родитель, Узел
o Левый потомок, Узел
o Правый потомок, Узел.
Инициализация сущности выполняется без аргументов.
Поведение сущности описывают следующие действия:
 Добавление значения. При добавлении значения возможно две ситуации
o Для данного узла Значение не было задано ранее. В этом случае оно задается и
работа завершается
o Для данного узла Значение ранее было задано. В этом случае определяется, больше
ли новое значение или меньше-равно чем текущее. Если больше – то значение
добавляется в правый потомок, иначе в левый. Если нужный потомок отсутствует,
то сначала он должен быть создан.
 Удаление значения. В качестве аргумента передается значение, которое нужно удалить.
Если такое значение есть, в самом узле или любом его потомке, то удаляется узел с этим
значением, но все его потомки должны остаться прикрепленными к структуре.
 Проверка на существование значения. В качестве аргумента передается значение, и
возвращается информация о том есть ли такое значение в самом узле или любом его
потомке.
 Приведение к строке. Результатом приведения узла к строке является перечень всех
значений хранимых в данном узле и всех его потомках, которое должно быть получено
левосторонним обходом в глубину.
После реализации сущности, создайте её экземпляр и добавить в него числа: 3 5 4 7 1 2. Выведите
на экран текстовое представление узла.
*/

public class Node {
    private Integer value;
    private Node parent;
    private Node leftChild;
    private Node rightChild;

    public Node() {
        this.value = null;
        this.parent = null;
        this.leftChild = null;
        this.rightChild = null;
    }

    public void addValue(int newValue) {
        if (this.value == null) {
            this.value = newValue;
            return;
        }

        if (newValue > this.value) {
            if (this.rightChild == null) {
                this.rightChild = new Node();
                this.rightChild.parent = this;
            }
            this.rightChild.addValue(newValue);
        } else {
            if (this.leftChild == null) {
                this.leftChild = new Node();
                this.leftChild.parent = this;
            }
            this.leftChild.addValue(newValue);
        }
    }

    public void removeValue(int valueToRemove) {
        Node nodeToRemove = findNode(valueToRemove);
        if (nodeToRemove == null) {
            return;
        }
        removeNode(nodeToRemove);
    }

    private Node findNode(int targetValue) {
        if (this.value == null) {
            return null;
        }

        if (this.value == targetValue) {
            return this;
        }

        if (targetValue > this.value && this.rightChild != null) {
            return this.rightChild.findNode(targetValue);
        } else if (this.leftChild != null) {
            return this.leftChild.findNode(targetValue);
        }
        return null;
    }

    private void removeNode(Node node) {
        if (node.parent == null) {
            if (node.leftChild != null) {
                this.value = node.leftChild.value;
                this.leftChild = node.leftChild.leftChild;
                this.rightChild = node.leftChild.rightChild;
                if (node.rightChild != null) {
                    addSubtree(node.rightChild);
                }
            } else if (node.rightChild != null) {
                this.value = node.rightChild.value;
                this.leftChild = node.rightChild.leftChild;
                this.rightChild = node.rightChild.rightChild;
            } else {
                this.value = null;
            }
        } else {
            Node parent = node.parent;
            boolean isLeftChild = (parent.leftChild == node);

            if (isLeftChild) {
                if (node.leftChild != null) {
                    parent.leftChild = node.leftChild;
                    node.leftChild.parent = parent;
                    if (node.rightChild != null) {
                        parent.addSubtree(node.rightChild);
                    }
                } else if (node.rightChild != null) {
                    parent.leftChild = node.rightChild;
                    node.rightChild.parent = parent;
                } else {
                    parent.leftChild = null;
                }
            } else {
                if (node.leftChild != null) {
                    parent.rightChild = node.leftChild;
                    node.leftChild.parent = parent;
                    if (node.rightChild != null) {
                        parent.addSubtree(node.rightChild);
                    }
                } else if (node.rightChild != null) {
                    parent.rightChild = node.rightChild;
                    node.rightChild.parent = parent;
                } else {
                    parent.rightChild = null;
                }
            }
        }
    }

    private void addSubtree(Node subtree) {
        if (subtree == null || subtree.value == null) {
            return;
        }

        addValue(subtree.value);
        if (subtree.leftChild != null) {
            addSubtree(subtree.leftChild);
        }
        if (subtree.rightChild != null) {
            addSubtree(subtree.rightChild);
        }
    }

    public boolean containsValue(int targetValue) {
        return findNode(targetValue) != null;
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        leftDepthTraversal(result);
        return result.toString().trim();
    }

    private void leftDepthTraversal(StringBuilder builder) {
        if (this.value == null) {
            return;
        }

        builder.append(this.value).append(" ");

        if (this.leftChild != null) {
            this.leftChild.leftDepthTraversal(builder);
        }

        if (this.rightChild != null) {
            this.rightChild.leftDepthTraversal(builder);
        }
    }
}