/**
 * The Locality Sensitive Hashing (LSH) library is part of the SEEKS project and 
 * does provide several locality sensitive hashing schemes for pattern matching over 
 * continuous and discrete spaces.
 * Copyright (C) 2006, 2009 Emmanuel Benazera, juban@free.fr
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

/**
 * \file$Id:
 * \brief Data structures and parameters for the locality sensitive hashing scheme.
 * \author E. Benazera, juban@free.fr
 */

#ifndef LSHSYSTEM_H
#define LSHSYSTEM_H

namespace lsh
{
   /**
    * \class LSHSystem
    * \brief parameters for the locality sensitive hashing scheme.
    */
   class LSHSystem
     {
      public:
	LSHSystem(const unsigned int &k, const unsigned int &L) 
	  :_k(k),_L(L)
	  {};
	
	~LSHSystem() {};
	
	/**
	 * Parameters L and k are ESSENTIALS to the locality sensitive hashing scheme.
	 * Here are the default value for now (testing). Any modification here can degrade/improve
	 * drastically the hashing mecanism (distributed or not). So don't tweak these if not sure
	 * of what you're doing.
	 */
	
	/**
	 * k: this is the local dispersion parameter.
	 */
	unsigned int _k;
	
	/**
	 * L: is the universal dispersion parameter, i.e. the total number of queries
	 * to the hashtable to get all the nearest neighbors within a certain distance
	 * to the query.
	 */
	unsigned int _L;

	/**
	 * Accessors.
	 */
	int getK () { return _k; };
	
	int getL () { return _L; };
		
	/**
	 * Maximum hashing random 32 bit integer as 2^29.
	 */
	static const unsigned int _max_hash_rnd = 536870912;
	
	/**
	 * prime number for the uniform hashing with bits.
	 */
	static const unsigned int _control_hash_prime_bits = 217645177;	

	/**
	 * prime number for the uniform hashing with real numbers, as 2^32 - 5.
	 */
	static const unsigned int _control_hash_prime_reals = 4294967291UL;
	
     protected:
     };
   
} /* end of namespace */

#endif
