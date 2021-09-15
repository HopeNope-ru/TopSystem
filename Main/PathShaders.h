#pragma once
#include "Defs.h"

namespace TopSystem {
  struct PathShaders
  {
  public:
	PathShaders(string vertexFilePath, string fragmentFilePath)
	  : vertexPath(vertexFilePath),
		fragmentPath(fragmentFilePath)
	{ }

	const string& GetVertexFilePath()	const { return vertexPath; }
	const string& GetFragmentFilePath() const { return fragmentPath; }

  private:
	string vertexPath;
	string fragmentPath;
  };
}