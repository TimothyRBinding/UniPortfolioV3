import { getRepository } from 'typeorm'
import { Business } from '../database/entity/Business'
import { getConnection } from 'typeorm'

//Get both location and title
/*
async function getAllLocationsAndBuisnesses(req, res) {

    let searchString = req.query.searchString ? req.query.searchString : ''
    let buisnessObj = await getConnection()
        .getRepository(Business)
        .find()
    if (searchString != '') {
        buisnessObj = buisnessObj.filter(business => business.name.includes(searchString))
    }

    res.json(buisnessObj)

    /*
    res.json(
        await getRepository(Business)
            .createQueryBuilder('business')
            .leftJoinAndSelect('business.locationMarker', 'locationMarker')
            .getMany(),
    )
}
*/

//Get both location and title
async function getAllLocationsAndBuisnesses(req, res) {
    res.json(
        await getRepository(Business)
            .createQueryBuilder('business')
            .leftJoinAndSelect('business.locationMarker', 'locationMarker')
            .getMany(),
        
    )
    res.send({
        Message: "test"
    })
}

//Get both location and title
async function getSearchString(req, res) {
    let searchString = req.query.searchString ? req.query.searchString : ''
    let buisnessObj = await getConnection()
        .getRepository(Business)
        .find()
    if (searchString != '') {
        buisnessObj = buisnessObj.filter(business => business.name.includes(searchString))
    }
    res.json(buisnessObj)
}

export default { getAllLocationsAndBuisnesses,  getSearchString }

/*
// returns all of the pizza data where the name contains the value in the optional search string parameter
async function getAllPizza(req, res) {
    let searchString = req.query.searchString ? req.query.searchString : ''
    let buisnessObj = await getConnection()
        .getRepository(Pizza)
        .find()
    if (searchString != '') {
        buisnessObj = buisnessObj.filter(pizza => pizza.name.includes(searchString))
    }

    res.json(buisnessObj)
}
*/