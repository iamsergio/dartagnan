bool dartMethodIsOverridden(String methodName) {
  final InstanceMirror reflectedClass = reflect(this);
  final methods = reflectedClass.type.instanceMembers;
  final methodMirror = methods[Symbol(methodName)];

  String str = methodMirror?.owner?.qualifiedName.toString();
  return str != "Symbol(\".%1\")";
}
