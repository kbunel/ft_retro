
Wall::Wall()
{}

Wall::Wall(Wall const & src)
{
  *this = src;
}

Wall::~Wall()
{}

Wall & Wall::operator=(Wall const & rhs)
{
  (void)rhs;
  return *this;
}
